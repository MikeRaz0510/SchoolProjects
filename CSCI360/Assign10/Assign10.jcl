//KC03E54A JOB ,'M.Rasmussen',MSGCLASS=H
//JSTEP01  EXEC PGM=ASSIST
//STEPLIB  DD DSN=KC00NIU.ASSIST.LOADLIB,DISP=SHR
//SYSPRINT DD SYSOUT=*
//SYSIN    DD *
*****************************************************************
*                                                               *
* CSCI 360-PE1           ASSIGNMENT 9               Spring 2023 *
* Packed Decimal                                                *
*                                                               *
* DEVELOPER NAME: Mike Rasmussen                                *
* DUE DATE: 4/21/23                                             *
*                                                               *
*****************************************************************
PAYROLL3 CSECT
*
*  STANDARD ENTRY LINKAGE WITH R12 AS BASE REGISTER
*
         STM   14,12,12(13)  SAVE REGS IN CALLER'S SAVE AREA
         LR    12,15         COPY CSECT ADDR INTO R12
         USING PAYROLL3,12   ESTABLISH R12 AS THE BASE REG
         LA    14,SAVEREGS   R14 POINTS TO THIS CSECT'S SAVE AREA
         ST    14,8(,13)     STORE ADDR OF THIS CSECT'S SAVE AREA
         ST    13,4(,14)     STORE ADDR OF CALLER'S SAVE AREA
         LR    13,14         POINT R13 AT THIS CSECT'S SAVE AREA
*
*
*  Here is where you will write your program.
*
         LA    11,4095(,12)  R11 -> R12 + 4095
         LA    11,1(,11)     R11 -> R12 + 4096
         USING PAYROLL3+4096,11        EST 2ND BASE REG
*
         LA    1,BTPARMS
         L     15,=V(BUILDTBL)
         BALR  14,15
*
         LA    1,BTPARMS
         L     15,=V(PROCTBL)
         BALR  14,15
*
*  STANDARD EXIT LINKAGE WITH RC OF 0
*
         SR    15,15        R15 = RETURN CODE OF 0
         L     13,4(,13)    POINT R13 TO CALLER'S SAVE AREA
         L     14,12(,13)   RESTORE REGISTER 14
         LM    0,12,20(13)  RESTORE R0 THRU R12
*
         BR    14           RETURN TO CALLER
*
         LTORG
*
SAVEREGS DS    18F          PROGRAM'S REGISTER SAVE AREA
*
* PACKED DECIMAL VARIABLES
*
*PPAGECTR DC    PL2'0'         PACKED PAGE COUNTER (MAX 999)
*
*PEMPID   DC    PL5'0'         PACKED EMPLOYEE ID
*PHRPAY   DC    PL3'0'         PACKED EMPLOYEE HOURLY PAY RATE
*PHOURS   DC    PL3'0'         PACKED EMPLOYEE HOURS WORKED
*PDEDUCT  DC    PL3'0'         PACKED EMPLOYEE DEDUCTION
*PBONUS   DC    PL3'0'         PACKED EMPLOYEE BONUS
*PEMPGPAY DC    PL6'0'         PACKED CALCULATED EMPLOYEE GROSS PAY
*PFEDWITH DC    PL6'0'         PACKED CALCULATED FEDERAL WITHHOLDING
*PSTWITH  DC    PL6'0'         PACKED CALCULATED STATE WITHHOLDING
*PEMPNPAY DC    PL6'0'         PACKED CALCULATED EMPLOYEE NET PAY
*
*PCALC    DC    PL10'0'        USED TO CALCULATE WITHHOLDING AND AVGS
*
*PTGRPAY  DC    PL7'0'         PACKED TOTAL GROSS EMPLOYEE PAY
*PTFWITH  DC    PL7'0'         PACKED TOTAL FED WITHHOLDING
*PTSWITH  DC    PL7'0'         PACKED TOTAL STATE WITHHOLDING
*PTNETPAY DC    PL7'0'         PACKED TOTAL NET EMPLOYEE PAY
*
*
BTPARMS  DC    A(PFWHPCT)     ADDRESS OF PFWHPCT
         DC    A(PSWHPCT)     ADDRESS OF PSWHPCT
         DC    A(EMPTBL)      ADDRESS OF EMPTBL
         DC    A(PEMPCTR)     ADDRESS OF PEMPCTR
*
EMPTBL   DS    120CL42
*
PFWHPCT  DC    PL4'0'         PACKED FEDERAL WITHHOLDING PERCENTAGE
PSWHPCT  DC    PL4'0'         PACKED STATE WITHHOLDING PERCENTAGE
*
PEMPCTR  DC    PL3'0'         PACKED EMPLOYEE COUNTER (MAX 999)
*
*
*  Here is where your storage will be defined.
*
* OUTPUT FIELDS
*
*
*
*RECORD   DS    0H     BUFFER FOR EMPLOYEE RECORD READ FROM INPUT FILE
*IEMPID   DS    ZL8    packs into 5 bytes
*IHRPAY   DS    ZL5    packs into 3 bytes
*IHOURS   DS    ZL5    packs into 3 bytes
*IDEDUCT  DS    ZL5    packs into 3 bytes
*IBONUS   DS    ZL5    packs into 3 bytes
*IEMPNME  DS    CL25
*         DS    CL27
*
*RECORD2  DS    0H   BUFFER FOR FED AND ST WH
*IFEDWH   DS    ZL6  INPUT FOR FED WH PCT
*ISTWH    DS    ZL6  INPUT FOR ST WH PCT
         DS    CL68 FILLS 80 BYTES
*
$TBLENT1 DSECT                1ST DSECT FOR ACCOUNT HOLDER TBL ENTRY
$PEMPID  DS    PL5            packs into 5 bytes
$PHRPAY  DS    PL3            packs into 3 bytes
$PHOURS  DS    PL3            packs into 3 bytes
$PDEDUCT DS    PL3            packs into 3 bytes
$PBONUS  DS    PL3            packs into 3 bytes
$EMPNME  DS    CL25
*
$RECORD  DSECT                DSECT FOR EACH INPUT RECORD
$IEMPID  DS    ZL8            packs into 5 bytes
$IHRPAY  DS    ZL5            packs into 3 bytes
$IHOURS  DS    ZL5            packs into 3 bytes
$IDEDUCT DS    ZL5            packs into 3 bytes
$IBONUS  DS    ZL5            packs into 3 bytes
$IEMPNME DS    CL25
*
BUILDTBL CSECT
         STM   14,12,12(13)   SAVE REGS IN CALLER'S SAVE AREA
         LR    12,15          COPY CSECT ADDRESS INTO R12
         USING BUILDTBL,12    ESTABLISH R12 AS THE BASE REG
         LA    14,BTSAVE      R14 POINTS TO THIS CSECT'S SAVE AREA
         ST    14,8(,13)      STORE ADDRESS OF THIS CSECT'S SAVE AREA
         ST    13,4(,14)      STORE ADDRESS OF CALLER'S SAVE AREA
         LR    13,14          POINT R13 AT THIS CSECT'S SAVE AREA
*
         LM    2,5,0(1)       R2 -> PFWHPCT(4) PACKED
*                             R3 -> PSWHPCT(4) PACKED
*                             R4 -> EMPTBL
*                             R5 -> PEMPCTR(3) PACKED
*
         XREAD RECORD,80     READ 1ST RECORD FOR PCTS
         PACK  0(4,2),RECORD(6)    PACK FED WH PCT
         PACK  0(4,3),RECORD+6(6)     PACK ST WH PCT
*
         LA    6,RECORD       R6 -> BEGINNING OF THE INPUT RECORD
         USING $RECORD,6      ESTABLISH ADDRESSABILITY FOR RECORD
*
         USING $TBLENT1,4     EATABLISH ADDRESSABILITY FOR TABLE ENTRY
*

*
         XREAD RECORD,80      READ FIRST CUSTOMER RECORD
*
LOOP1   BNZ   ENDLOOP1       BRANCH IF NO RECORD
*
         AP    0(3,5),=PL1'1' ADD 1 TO ACCOUNT COUNTER
*
         PACK  $PEMPID(5),$IEMPID(8)     PACK EMPID
         PACK  $PHRPAY(3),$IHRPAY(5)     PACK HOURLY PAY
         PACK  $PHOURS(3),$IHOURS(5)     PACK HOURS WORKED
         PACK  $PDEDUCT(3),$IDEDUCT(5)   PACK DEDUCTIONS
         PACK  $PBONUS(3),$IBONUS(5)     PACK BONUS
         MVC   $EMPNME(25),$IEMPNME      MOVE EMP NAME
*
         LA    4,42(,4)       R2 -> NEXT ENTRY IN TABLE
*
         XREAD RECORD,80      READ NEXT RECORD
*
         B     LOOP1          BRANCH BACK TO TOP OF LOOP1
*
         DROP  6,4
*
ENDLOOP1 SR    15,15          R15 = RETURN CODE OF 0
         L     13,4(,13)      POINT R13 TO CALLER'S SAVE AREA
         L     14,12(,13)     RESTORE REGISTER 14
         LM    0,12,20(13)    RESTORE R0 THRU R12
         BR    14             RETURN TO CALLER
*
         LTORG                LITERAL ORGANIZATION
*
BTSAVE   DS    18F            REGISTER SAVE AREA
*
RECORD      DS    CL80
*
*        END   BUILDTBL   NOT AN ACTUAL END STATEMENT BUT HELPS TO
*                         RECOGNIZE WHERE BUILDTBL ENDS AND THE NEXT
*                         CSECT BEGINS
*
PTPARMS  DC    A(PFWHPCT)          ADDRESS OF PFWHPCT
         DC    A(PSWHPCT)          ADDRESS OF PSWHPCT
         DC    A(EMPTBL)           ADDRESS OF EMPTBL
         DC    A(PEMPCTR)          ADDRESS OF PEMPCTRS
*
$TBLENT2 DSECT                2ND DSECT FOR ACCOUNT HOLDER TBL ENTRY
$PEMPID2 DS    PL5            packs into 5 bytes
$PHRPAY2 DS    PL3            packs into 3 bytes
$PHOURS2 DS    PL3            packs into 3 bytes
$PDDUCT2 DS    PL3            packs into 3 bytes
$PBONUS2 DS    PL3            packs into 3 bytes
$EMPNME2 DS    CL25
*
*
PROCTBL  CSECT
         STM   14,12,12(13)   SAVE REGS IN CALLER'S SAVE AREA
         LR    12,15          COPY CSECT ADDRESS INTO R12
         USING PROCTBL,12     ESTABLISH R12 AS THE BASE REG
         LA    14,PTSAVE      R14 POINTS TO THIS CSECT'S SAVE AREA
         ST    14,8(,13)      STORE ADDRESS OF THIS CSECT'S SAVE AREA
         ST    13,4(,14)      STORE ADDRESS OF CALLER'S SAVE AREA
         LR    13,14          POINT R13 AT THIS CSECT'S SAVE AREA
*
         LM    2,5,0(1)       R2 -> PFWHPCT(4) PACKED
*                             R3 -> PSWHPCT(4) PACKED
*                             R4 -> EMPTBL
*                             R5 -> PEMPCTR(3) PACKED
         USING $TBLENT2,2     EST. ADDRESSABILITY FOR TBL ENTRY DSECT
*
         ZAP   DBLWORD(8),0(3,5)  PUT ACCTCTR IN DOUBLE WORD
         CVB   4,DBLWORD      CONVERT ACCTCTR TO BINARY IN R4
*
LOOP2    MVC   OEMPID(10),=X'21202060202020202020'
         ED    OEMPID(10),$PEMPID2       DISPLAY EMP ID NUM
*
         MVC   OEMPNME(25),$EMPNME2 COPY EMP NAME TO DETAIL LINE
*
         LA    1,OHRPAY+3              SET OFF 3B IN R1
         MVC   OHRPAY(7),=X'402021204B2020'
         EDMK  OHRPAY(7),$PHRPAY2        DISPLAY PAY RATE
         BCTR  1,0                     DEREMENT R1
         MVI   0(1),C'$'               SET $
*
         MVC   OHOURS(7),=X'402021204B2020'
         ED    OHOURS(7),$PHOURS2        DISPLAY HOURS WORKED
*
         ZAP   PEMPGPAY(6),$PHRPAY2(3)   ZERO AND ADD PAYRATE TO GROSS
         MP    PEMPGPAY(6),$PHOURS2(3)   MULTIPLY GROSS BY HOURS
         SRP   PEMPGPAY(6),64-2,5      SHIFT AND ROUND
         SP    PEMPGPAY(6),$PDDUCT2(3)  SUBTRACT DEDUCTIONS
         AP    PEMPGPAY(6),$PBONUS2(3)   ADD BONUSES
*
         LA    1,OEMPGPAY+8            SET OFF 8B IN R1
         MVC   OEMPGPAY(12),=X'40202020206B2021204B2020'
         EDMK  OEMPGPAY(12),PEMPGPAY+1 DISPLAY GROSS PAY
         BCTR  1,0                     DECREMENT R1
         MVI   0(1),C'$'               SET $
         XPRNT DETAIL,133     PRINT THE DETAIL LINE
*
         LA    2,42(,2)       ADVANCE TO NEXT TABLE ENTRY
*
         BCT   4,LOOP2        IF ANOTHER ENTRY, BRANCH BACK TO LOOP2
*
*         DROP  6,2
*
         XPRNT HEADER1,133             PRINT
         XPRNT HEADER2,133             PRINT
         XPRNT HEADER4,133             PRINT
         XPRNT TOTALS1,133             PRINT
         XPRNT TOTALS2,133             PRINT
         XPRNT TOTALS3,133             PRINT
         XPRNT TOTALS4,133             PRINT
         XPRNT TOTALS5,133             PRINT
*
         SR    15,15          R15 = RETURN CODE OF 0
         L     13,4(,13)      POINT R13 TO CALLER'S SAVE AREA
         L     14,12(,13)     RESTORE REGISTER 14
         LM    0,12,20(13)    RESTORE R0 THRU R12
         BR    14             RETURN TO CALLER
*
         LTORG                LITERAL ORGANIZATION
*
PTSAVE   DS    18F            REGISTER SAVE AREA
*
PEMPID   DC    PL5'0'         PACKED EMPLOYEE ID
PHRPAY   DC    PL3'0'         PACKED EMPLOYEE HOURLY PAY RATE
PHOURS   DC    PL3'0'         PACKED EMPLOYEE HOURS WORKED
PDEDUCT  DC    PL3'0'         PACKED EMPLOYEE DEDUCTION
PBONUS   DC    PL3'0'         PACKED EMPLOYEE BONUS
PEMPGPAY DC    PL6'0'         PACKED CALCULATED EMPLOYEE GROSS PAY
PFEDWITH DC    PL6'0'         PACKED CALCULATED FEDERAL WITHHOLDING
PSTWITH  DC    PL6'0'         PACKED CALCULATED STATE WITHHOLDING
PEMPNPAY DC    PL6'0'         PACKED CALCULATED EMPLOYEE NET PAY
*
CNPPARMS DC A(PEMPGPAY) <- declared in PROCTBL
         DC A(PEMPNPAY) <- declared in PROCTBL
         DC A(0) <- declared in PAYROLL3 and passed into PROCTBL
         DC A(PFEDWITH) <- declared in PROCTBL
         DC A(0) <- declared in PAYROLL3 and passed into PROCTBL
         DC A(PSTWITH) <- declared in PROCTBL
*
DBLWORD  DC    D'0'           DOUBLEWORD ON DOUBLEWORD BOUNDARY
*
* OUTPUT FIELDS
*
DETAIL   DC    C'0'   CARRIAGE CONTROL CHARACTER
OEMPID   DS    CL10   OUTPUT FIELD FOR EMPLOYEE NAME
         DC    2C' '  SPACES
OEMPNME  DS    CL25   OUTPUT FIELD FOR EMPLOYEE ID
         DC    3C' '  SPACES
OHRPAY   DS    CL7    OUTPUT FIELD FOR PAY RATE
         DC    3C' '  SPACES
OHOURS   DS    CL7    OUTPUT FIELD FOR HOURS WORKED
         DC    8C' '  SPACES
OEMPGPAY DS    CL12   OUTPUT FIELD FOR GROSS PAY
         DC    8C' '  SPACES
OFEDWITH DS    CL12   OUTPUT FIELD FOR FED WH
         DC    6C' '  SPACES
OSTWITH  DS    CL12   OUTPUT FIELD FOR STATE WH
         DC    5C' '  SPACES
OEMPNPAY DS    CL12   OUTPUT FIELD FOR NET PAY
*
HEADER1  DC    C'0'       CARRIAGE CONTROL CHARACTER
         DC    50C' '     SPACES
         DC    C'STATE OF ILLINOIS NATIONAL BANK'
         DC    40C' '     SPACES
         DC    C'PAGE:  ' LABEL
OPAGE    DS    CL4        OUTPUT FIELD FOR PAGE NUMBER
*
HEADER2  DC    C' '       CARRIAGE CONTROL CHARACTER
         DC    48C' '     SPACES
         DC    C'SEMI-MONTHLY EMPLOYEE PAYROLL REPORT'
         DC    58C' '     SPACES
*
HEADER3  DC    C' '       CARRIAGE CONTROL CHARACTER
         DC    132C' '    SPACES
*
HEADER4  DC    C' '       CARRIAGE CONTROL CHARACTER
         DC    63C' '     SPACES
         DC    C'TOTALS'  LABEL
         DC    63C' '     SPACES
*
COLHDR1  DC    C'0'                    CARRIAGE CONTROL CHARACTER
         DC    C'EMPLOYEE'             LABEL
         DC    3C' '                   SPACES
         DC    C'EMPLOYEE'             LABEL
         DC    20C' '                  SPACES
         DC    C'HOURLY'               LABEL
         DC    6C' '                   SPACES
         DC    C'HOURS'                LABEL
         DC    12C' '                  SPACES
         DC    C'EMPLOYEE'             LABEL
         DC    4C' '                   SPACES
         DC    C'EMPLOYEE FEDERAL'     LABEL
         DC    4C' '                   SPACES
         DC    C'EMPLOYEE STATE'       LABEL
         DC    10C' '                  SPACES
         DC    C'EMPLOYEE'             LABEL
*
COLHDR2  DC    C' '                    CARRIAGE CONTROL CHARACTER
         DC    C'ID'                   LABEL
         DC    9C' '                   SPACES
         DC    C'NAME'                 LABEL
         DC    27C' '                  SPACES
         DC    C'PAY'                  LABEL
         DC    5C' '                   SPACES
         DC    C'WORKED'               LABEL
         DC    11C' '                  SPACES
         DC    C'GROSS PAY'            LABEL
         DC    9C' '                   SPACES
         DC    C'WITHHOLDING'          LABEL
         DC    7C' '                   SPACES
         DC    C'WITHHOLDING'          LABEL
         DC    11C' '                  SPACES
         DC    C'NET PAY'              LABEL
*
HYPHENS1 DC    C' '         CARRIAGE CONTROL CHARACTER
         DC    9C'-'        HYPHENS
         DC    2C' '        SPACE
         DC    25C'-'       HYPHENS
         DC    3C' '        SPACE
         DC    7C'-'        HYPHENS
         DC    3C' '        SPACE
         DC    7C'-'        HYPHENS
         DC    5C' '        SPACE
         DC    15C'-'       HYPHENS
         DC    4C' '        SPACE
         DC    16C'-'       HYPHENS
         DC    4C' '        SPACE
         DC    14C'-'       HYPHENS
         DC    3C' '        SPACE
         DC    15C'-'       HYPHENS
*
TOTALS1  DC    C'0'          CARRIAGE CONTROL
         DC    6C' '         SPACES
         DC    C'NUMBER OF EMPLOYEES:'         LABEL
         DC    13C' '        SPACES
OEMPCTR  DS    CL5           OUTPUT FOR EMP CTR
         DC    89C' '        SPACES
*
TOTALS2  DC    C'0'          CARRIAGE CONTROL
         DC    10C' '        SPACES
         DC    C'TOTAL GROSS PAY:'     LABEL
         DC    5C' '         SPACES
OTGPAY   DS    CL14          OUTPUT FOR TOT GROSS PAY
         DC    20C' '       SPACES
         DC    C'AVERAGE GROSS PAY:'   LABEL
OAGPAY   DS    CL14          OUTPUT FOR AVG GROSS PAY
         DC    35C' '        SPACES
*
TOTALS3  DC    C'0'          CARRIAGE CONTROL
         DC    C'TOTAL FEDERAL WITHHOLDING:'
         DC    5C' '         SPACES
OTFWITH  DS    CL12          OUTPUT FOR TOT FED WH
         DC    12C' '        SPACES
         DC    C'AVERAGE FEDERAL WITHHOLDING:'
OAFWITH  DS    CL14          OUTPUT FOR AVG FED WH
         DC    35C' '        SPACES
*
TOTALS4  DC    C'0'          CARRIAGE CONTROL
         DC    C'  TOTAL STATE WITHHOLDING:'
         DC    5C' '         SPACES
OTSTWITH DS    CL12          OUTPUT FOR TOT ST WH
         DC    14C' '        SPACES
         DC    C'AVERAGE STATE WITHHOLDING:'
OASWITH  DS    CL14          OUTPUT FOR AVG ST WH
         DC    35C' '        SPACES
*
TOTALS5  DC    C'0'          CARRIAGE CONTROL
         DC    12C' '        SPACES
         DC    C'TOTAL NET PAY:'
         DC    5C' '         SPACES
OTNPAY   DS    CL12          OUTPUT FOR TOT NET PAY
         DC    24C' '        SPACES
         DC    C'AVERAGE NET PAY:'
OANPAY   DS    CL14          OUTPUT FOR AVG NET PAY
         DC    35C' '        SPACES
*
         END   PROCTBL
         END   PAYROLL3
