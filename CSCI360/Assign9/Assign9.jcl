//KC03E54A JOB ,'M.Rasmussen',MSGCLASS=H
//JSTEP01  EXEC PGM=ASSIST
//STEPLIB  DD DSN=KC00NIU.ASSIST.LOADLIB,DISP=SHR
//SYSPRINT DD SYSOUT=*
//SYSIN    DD *
//
//FT05F001 DD DSN=KC02322.CSCI360.ASNDATA(DATA9),DISP=SHR
//
//FT06F001 DD SYSOUT=*
//
*****************************************************************                           
*                                                               *                           
* CSCI 360-PE1           ASSIGNMENT 9               Spring 2023 *                           
* Packed Decimal                                                *                           
*                                                               *                           
* DEVELOPER NAME: Mike Rasmussen                                *                           
* DUE DATE: 4/21/23                                             *                           
*                                                               *                           
*****************************************************************    
PAYROLL2 CSECT
STM   14,12,12(13)  SAVE REGS IN CALLER'S SAVE AREA
LR    12,15         COPY CSECT ADDR INTO R12
USING PAYROLL2,12   ESTABLISH R12 AS THE BASE REG
LA    14,SAVEREGS   R14 POINTS TO THIS CSECT'S SAVE AREA
ST    14,8(,13)     STORE ADDR OF THIS CSECT'S SAVE AREA
ST    13,4(,14)     STORE ADDR OF CALLER'S SAVE AREA
LR    13,14         POINT R13 AT THIS CSECT'S SAVE AREA
XREAD RECORD2,80      GET WITHHOLDING PCTS
PACK  PFWHPCT(4),IFEDWH(6)    PACK FED WH PCT
PACK  PSWHPCT(4),ISTWH(6)     PACK ST WH PCT
LA    2,99          LOAD 99 INTO R2 FOR LINE COUNTER
XREAD RECORD,80      GET FIRST EMPLOYEE RECORD
BC   B'0100',ENDLOOP1  BRANCH TO ENDLOOP1 IF EOF
MVI   DETAIL+1,C' '
MVC   DETAIL+2(131),DETAIL+1
AP    PEMPCTR(3),P1(1)        INCREMENT EMP COUNT
LA    2,1(,2)                 INCREMENT LINE COUNTER
PACK  PEMPID(5),IEMPID(8)     PACK EMPID
PACK  PHRPAY(3),IHRPAY(5)     PACK HOURLY PAY
PACK  PHOURS(3),IHOURS(5)     PACK HOURS WORKED
PACK  PDEDUCT(3),IDEDUCT(5)   PACK DEDUCTIONS
PACK  PBONUS(3),IBONUS(5)     PACK BONUS
MVC   OEMPNME(25),IEMPNME     MOVE EMP NAME TO OUTPUT
MVC   OEMPID(10),=X'21202060202020202020'
ED    OEMPID(10),PEMPID       DISPLAY EMP ID NUM
LA    1,OHRPAY+3              SET OFF 3B IN R1
MVC   OHRPAY(7),=X'402021204B2020'
EDMK  OHRPAY(7),PHRPAY        DISPLAY PAY RATE
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
MVC   OHOURS(7),=X'402021204B2020'
ED    OHOURS(7),PHOURS        DISPLAY HOURS WORKED
ZAP   PEMPGPAY(6),PHRPAY(3)   ZERO AND ADD PAYRATE TO GROSS
MP    PEMPGPAY(6),PHOURS(3)   MULTIPLY GROSS BY HOURS
SRP   PEMPGPAY(6),64-2,5      SHIFT AND ROUND
SP    PEMPGPAY(6),PDEDUCT(3)  SUBTRACT DEDUCTIONS
AP    PEMPGPAY(6),PBONUS(3)   ADD BONUSES
LA    1,OEMPGPAY+8            SET OFF 8B IN R1
MVC   OEMPGPAY(12),=X'40202020206B2021204B2020'
EDMK  OEMPGPAY(12),PEMPGPAY+1 DISPLAY GROSS PAY
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
AP    PTGRPAY(7),PEMPGPAY(6)  ADD TO THE TOTAL GROSS PAY
ZAP   PCALC(10),PEMPGPAY(6)   ZERO AND ADD GPAY TO CALC
MP    PCALC(10),PFWHPCT(4)    MULTIPLY BY WH PCT
SRP   PCALC(10),64-5,5        SHIFT AND ROUND
ZAP   PFEDWITH(6),PCALC(10)   STORE CALC IN FEDWITH
LA    1,OFEDWITH+8            SET OFF 8B IN R1
MVC   OFEDWITH(12),=X'40202020206B2021204B2020'
EDMK  OFEDWITH(12),PFEDWITH+1 DISPLAY FED WITHHOLDING
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
AP    PTFWITH(7),PFEDWITH(6)  ADD TO THE TOTAL FED WITH
ZAP   PCALC(10),PEMPGPAY(6)   ZERO AND ADD GPAY TO CALC
MP    PCALC(10),PSWHPCT(4)    MULTIPLY BY ST WH PCT
SRP   PCALC(10),64-5,5        SHIFT AND ROUND
ZAP   PSTWITH(6),PCALC(10)    STORE CALC IN STWITH
LA    1,OSTWITH+8             SET OFF 8B IN R1
MVC   OSTWITH(12),=X'40202020206B2021204B2020'
EDMK  OSTWITH(12),PSTWITH+1   DISPLAY ST WITHHOLDING
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
AP    PTSWITH(7),PSTWITH(6)   ADD TO THE TOTAL FED WITH
ZAP   PEMPNPAY(6),PEMPGPAY(6) STORE GPAY INTO NPAY
SP    PEMPNPAY(6),PFEDWITH(6) SUBTRACT FEDWITH FROM NET
SP    PEMPNPAY(6),PSTWITH(6)  SUBTRACT STWITH FROM NET
LA    1,OEMPNPAY+8            SET OFF 8B IN R1
MVC   OEMPNPAY(12),=X'40202020206B2021204B2020'
EDMK  OEMPNPAY(12),PEMPNPAY+1 DISPLAY NET PAY
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
AP    PTNETPAY(7),PEMPNPAY(6) ADD TO THE TOTAL FED WITH
C     2,=F'16'                COMPARE REG2 TO 16
BC    B'1101',ENDLOOP2        BRANCH TO ENDLOOP 2 IF CND NOT MET
AP    PPAGECTR(2),P1(1)       INCREMENT PAGE COUNTER
MVC   OPAGE(4),=X'40202120'
ED    OPAGE(4),PPAGECTR       DISPLAY PAGE COUNT
XPRNT HEADER1,133             PRINT
XPRNT HEADER2,133             PRINT
XPRNT COLHDR1,133             PRINT
XPRNT COLHDR2,133             PRINT
XPRNT HYPHENS1,133            PRINT
SR    2,2                     SET LINE COUNTER BACK TO 0
ENDLOOP2 DS    0H
XPRNT DETAIL,133     PRINT THE EMPLOYEE DETAIL RECORD
XREAD RECORD,80      READ NEXT EMPLOYEE RECORD
BC    B'1111',LOOP1  BRANCH TO TOP OF LOOP1 TO CHECK EOF
ENDLOOP1 DS    0H
AP    PPAGECTR(2),P1(1)       INCREMENT PAGE COUNTER
MVC   OPAGE(4),=X'40202120'
ED    OPAGE(4),PPAGECTR       DISPLAY PAGE COUNT
MVC   OEMPCTR(5),=X'2020202120'
ED    OEMPCTR(5),PEMPCTR      DISPLAY EMP COUNT
LA    1,OTGPAY+10             SET OFF 10B IN R1
MVC   OTGPAY(14),=X'402020202020206B2021204B2020'
EDMK  OTGPAY(14),PTGRPAY+1    DISPLAY TOTAL GROSS PAY
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
LA    1,OTFWITH+10            SET OFF 10B IN R1
MVC   OTFWITH(14),=X'402020202020206B2021204B2020'
EDMK  OTFWITH(14),PTFWITH+1   DISPLAY TOTAL FED WH
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
LA    1,OTSTWITH+10           SET OFF 10B IN R1
MVC   OTSTWITH(14),=X'402020202020206B2021204B2020'
EDMK  OTSTWITH(14),PTSWITH+1  DISPLAY TOTAL STATE WH
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
LA    1,OTNPAY+10             SET OFF 10B IN R1
MVC   OTNPAY(14),=X'402020202020206B2021204B2020'
EDMK  OTNPAY(14),PTNETPAY+1   DISPLAY TOTAL NET PAY
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
ZAP    PCALC(10),PTGRPAY(7)   STORE TOTAL GROSS IN PCALC
SRP    PCALC(10),3,0          SHIFT 3 TO THE LEFT
DP     PCALC(10),PEMPCTR(3)   DIVIDE TOT GROSS BY NUM OF EMPS
SRP    PCALC(7),64-3,5        SHIFT AND ROUND
LA    1,OAGPAY+10             SET OFF 10B IN R1
MVC   OAGPAY(14),=X'402020202020206B2021204B2020'
EDMK  OAGPAY(14),PCALC+1      DISPLAY AVG GROSS PAY
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
ZAP    PCALC(10),PTFWITH(7)   STORE TOTAL F WITH IN PCALC
SRP    PCALC(10),3,0          SHIFT 3 TO THE LEFT
DP     PCALC(10),PEMPCTR(3)   DIVIDE TOT FED WH BY NUM OF EMPS
SRP    PCALC(7),64-3,5        SHIFT AND ROUND
LA    1,OAFWITH+10            SET OFF 10B IN R1
MVC   OAFWITH(14),=X'402020202020206B2021204B2020'
EDMK  OAFWITH(14),PCALC+1     DISPLAY AVG FED WITH
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
ZAP    PCALC(10),PTSWITH(7)   STORE TOTAL S WITH IN PCALC
SRP    PCALC(10),3,0          SHIFT 3 TO THE LEFT
DP     PCALC(10),PEMPCTR(3)   DIVIDE TOT ST WH BY NUM OF EMPS
SRP    PCALC(7),64-3,5        SHIFT AND ROUND
LA    1,OASWITH+10            SET OFF 10B IN R1
MVC   OASWITH(14),=X'402020202020206B2021204B2020'
EDMK  OASWITH(14),PCALC+1     DISPLAY AVG STATE WITH
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
ZAP    PCALC(10),PTNETPAY(7)  STORE TOTAL NET PAY IN PCALC
SRP    PCALC(10),3,0          SHIFT 3 TO THE LEFT
DP     PCALC(10),PEMPCTR(3)   DIVIDE TOT NET BY NUM OF EMPS
SRP    PCALC(7),64-3,5        SHIFT AND ROUND
LA    1,OANPAY+10             SET OFF 10B IN R1
MVC   OANPAY(14),=X'402020202020206B2021204B2020'
EDMK  OANPAY(14),PCALC+1      DISPLAY TOTAL NET PAY
BCTR  1,0                     DECREMENT R1
MVI   0(1),C'$'               SET $
XPRNT HEADER1,133             PRINT
XPRNT HEADER2,133             PRINT
XPRNT HEADER4,133             PRINT
XPRNT TOTALS1,133             PRINT
XPRNT TOTALS2,133             PRINT
XPRNT TOTALS3,133             PRINT
XPRNT TOTALS4,133             PRINT
XPRNT TOTALS5,133             PRINT
SR    15,15        R15 = RETURN CODE OF 0
L     13,4(,13)    POINT R13 TO CALLER'S SAVE AREA
L     14,12(,13)   RESTORE REGISTER 14
LM    0,12,20(13)  RESTORE R0 THRU R12
BR    14           RETURN TO CALLER
LTORG
=X'40202020206B2021204B2020'
=F'16'
=X'40202120'
=X'21202060202020202020'
=X'402020202020206B2021204B2020'
=X'402021204B2020'
=X'2020202120'
SAVEREGS DS    18F          PROGRAM'S REGISTER SAVE AREA
PFWHPCT  DC    PL4'0'         PACKED FEDERAL WITHHOLDING PERCENTAGE
PSWHPCT  DC    PL4'0'         PACKED STATE WITHHOLDING PERCENTAGE
PEMPCTR  DC    PL3'0'         PACKED EMPLOYEE COUNTER (MAX 999)
PPAGECTR DC    PL2'0'         PACKED PAGE COUNTER (MAX 999)
PEMPID   DC    PL5'0'         PACKED EMPLOYEE ID
PHRPAY   DC    PL3'0'         PACKED EMPLOYEE HOURLY PAY RATE
PHOURS   DC    PL3'0'         PACKED EMPLOYEE HOURS WORKED
PDEDUCT  DC    PL3'0'         PACKED EMPLOYEE DEDUCTION
PBONUS   DC    PL3'0'         PACKED EMPLOYEE BONUS
PEMPGPAY DC    PL6'0'         PACKED CALCULATED EMPLOYEE GROSS PAY
PFEDWITH DC    PL6'0'         PACKED CALCULATED FEDERAL WITHHOLDING
PSTWITH  DC    PL6'0'         PACKED CALCULATED STATE WITHHOLDING
PEMPNPAY DC    PL6'0'         PACKED CALCULATED EMPLOYEE NET PAY
PCALC    DC    PL10'0'        USED TO CALCULATE WITHHOLDING AND AVGS
PTGRPAY  DC    PL7'0'         PACKED TOTAL GROSS EMPLOYEE PAY
PTFWITH  DC    PL7'0'         PACKED TOTAL FED WITHHOLDING
PTSWITH  DC    PL7'0'         PACKED TOTAL STATE WITHHOLDING
PTNETPAY DC    PL7'0'         PACKED TOTAL NET EMPLOYEE PAY
P1       DC    PL1'1'         ONE
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
HEADER1  DC    C'0'       CARRIAGE CONTROL CHARACTER
DC    50C' '     SPACES
DC    C'STATE OF ILLINOIS NATIONAL BANK'
DC    40C' '     SPACES
DC    C'PAGE:  ' LABEL
OPAGE    DS    CL4        OUTPUT FIELD FOR PAGE NUMBER
HEADER2  DC    C' '       CARRIAGE CONTROL CHARACTER
DC    48C' '     SPACES
DC    C'SEMI-MONTHLY EMPLOYEE PAYROLL REPORT'
DC    58C' '     SPACES
HEADER3  DC    C' '       CARRIAGE CONTROL CHARACTER
DC    132C' '    SPACES
HEADER4  DC    C' '       CARRIAGE CONTROL CHARACTER
DC    63C' '     SPACES
DC    C'TOTALS'  LABEL
DC    63C' '     SPACES
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
TOTALS1  DC    C'0'          CARRIAGE CONTROL
DC    6C' '         SPACES
DC    C'NUMBER OF EMPLOYEES:'         LABEL
DC    13C' '        SPACES
OEMPCTR  DS    CL5           OUTPUT FOR EMP CTR
DC    89C' '        SPACES
TOTALS2  DC    C'0'          CARRIAGE CONTROL
DC    10C' '        SPACES
DC    C'TOTAL GROSS PAY:'     LABEL
DC    5C' '         SPACES
OTGPAY   DS    CL14          OUTPUT FOR TOT GROSS PAY
DC    20C' '       SPACES
DC    C'AVERAGE GROSS PAY:'   LABEL
OAGPAY   DS    CL14          OUTPUT FOR AVG GROSS PAY
DC    35C' '        SPACES
TOTALS3  DC    C'0'          CARRIAGE CONTROL
DC    C'TOTAL FEDERAL WITHHOLDING:'
DC    5C' '         SPACES
OTFWITH  DS    CL12          OUTPUT FOR TOT FED WH
DC    12C' '        SPACES
DC    C'AVERAGE FEDERAL WITHHOLDING:'
OAFWITH  DS    CL14          OUTPUT FOR AVG FED WH
DC    35C' '        SPACES
TOTALS4  DC    C'0'          CARRIAGE CONTROL
DC    C'  TOTAL STATE WITHHOLDING:'
DC    5C' '         SPACES
OTSTWITH DS    CL12          OUTPUT FOR TOT ST WH
DC    14C' '        SPACES
DC    C'AVERAGE STATE WITHHOLDING:'
OASWITH  DS    CL14          OUTPUT FOR AVG ST WH
DC    35C' '        SPACES
TOTALS5  DC    C'0'          CARRIAGE CONTROL
DC    12C' '        SPACES
DC    C'TOTAL NET PAY:'
DC    5C' '         SPACES
OTNPAY   DS    CL12          OUTPUT FOR TOT NET PAY
DC    24C' '        SPACES
DC    C'AVERAGE NET PAY:'
OANPAY   DS    CL14          OUTPUT FOR AVG NET PAY
DC    35C' '        SPACES
RECORD   DS    0H     BUFFER FOR EMPLOYEE RECORD READ FROM INPUT FILE
IEMPID   DS    ZL8    packs into 5 bytes
IHRPAY   DS    ZL5    packs into 3 bytes
IHOURS   DS    ZL5    packs into 3 bytes
IDEDUCT  DS    ZL5    packs into 3 bytes
IBONUS   DS    ZL5    packs into 3 bytes
IEMPNME  DS    CL25
DS    CL27
RECORD2  DS    0H   BUFFER FOR FED AND ST WH
IFEDWH   DS    ZL6  INPUT FOR FED WH PCT
ISTWH    DS    ZL6  INPUT FOR ST WH PCT
DS    CL68 FILLS 80 BYTES
END   PAYROLL2
