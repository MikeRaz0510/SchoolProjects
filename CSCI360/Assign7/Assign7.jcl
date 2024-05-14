//KC03E54A JOB ,'M.Rasmussen',MSGCLASS=H
//JSTEP01  EXEC PGM=ASSIST
//STEPLIB  DD DSN=KC00NIU.ASSIST.LOADLIB,DISP=SHR
//SYSPRINT DD SYSOUT=*
//SYSIN    DD *
//
//FT05F001 DD DSN=KC02322.CSCI360.ASNDATA(DATA6),DISP=SHR
//
//FT06F001 DD SYSOUT=*
//
*****************************************************************
*                                                               *
* CSCI 360-PE1           ASSIGNMENT 7               Spring 2023 *
* Report Finishing                                              *
*                                                               *
* DEVELOPER NAME: Mike Rasmussen                                *
* DUE DATE: 3/31/23                                             *
*                                                               *
*****************************************************************
*                                                              
ASSIGN7  CSECT                                                  
         USING ASSIGN7,15     ESTABLISH ADDRESSABILITY ON REG 15
*                                                              
         LA    10,16          GET FED WITHHOLDING PERCENT INTO R10
         LA    11,4           GET STATE WITHHOLDING PERCENT INTO R11
*                                                              
         LA    8,99           SET REG8 TO 99 FOR LINE COUNTER  
         SR    9,9            SET REG9 TO 0 FOR PAGE COUNTER   
*                                                              
         XREAD RECORD,80      GET FIRST EMPLOYEE RECORD        
*                                                              
LOOP1    BC   B'0100',ENDLOOP1  BRANCH TO ENDLOOP1 IF EOF       
*                                                              
*  HERE IS WHERE THE BODY OF YOUR LOOP WILL BE CODED           
*                                                              
         L     4,EMPNUM       LOAD REG4 WITH NUM OF EMP        
         LA    4,1(,4)        INCREMENT NUM OF EMP             
         ST    4,EMPNUM       STORE NEW NUM OF EMP             
*                                                              
         LA    8,1(,8)        INCREMENT LINE COUNTER           
         MVC   OEMPNME(25),RECORD   COPY 25B FROM REC TO OEMPNME
         MVC   OEMPID(5),RECORD+25  COPY 5B FROM 26thB OF REC TO OEMPID
*                                                              
         XDECI 2,RECORD+31    GET PAY RATE                     
         XDECO 2,OPAYRATE     DISPLAY PAY RATE                 
         XDECI 3,0(1)         GET HOURS                        
         XDECO 3,OHOURS       DISPLAY HOURS                    
*                                                              
         MR    2,2            MULTIPLY PAY AND HOURS (R3 HAS PROD)
*                                                              
         XDECI 2,0(1)         GET DEDUCTIONS                   
         SR    3,2            SUBTRACT DEDUCTIONS FROM PAY     
         XDECI 2,0(1)         GET BONUS                        
         AR    3,2            ADD BONUS TO PAY                 
*                                                              
         XDECO 3,OGROSS       DISPLAY GROSS PAY                
*                                                              
         L     4,GROSST       LOAD GROSS TOTAL INTO REG4       
         AR    4,3            ADD THIS EMP GROSS PAY TO TOTAL  
         ST    4,GROSST       STORE NEW GROSS PAY TOTAL        
*                                                              
         LR    5,3            COPY GROSS PAY FROM REG3 INTO REG5
         MR    4,10           MULTIPLY GROSS PAY BY FED TAX%   
         D     4,=F'100'      DIVIDE REG5 BY 100               
         XDECO 5,OFEDWH       DISPLAY FED WITHHOLDING          
*                                                              
         L     4,FEDWHT       LOAD REG4 WITH FED WITHHOLDING TOTAL
         AR    4,5            ADD THIS EMP FED WH TO THE TOTAL 
         ST    4,FEDWHT       STORE THE NEW TOTAL              
*                                                              
         LR    7,3            COPY GROSS PAY FROM REG3 INTO REG7
         MR    6,11           MULTIPLY GROSS PAY BY STATE TAX%
         D     6,=F'100'      DIVIDE REG7 BY 100               
         XDECO 7,OSTWH        DISPLAY STATE WITHHOLDING        
*                                                              
         L     4,STWHT        LOAD THE STATE WH TOTAL INTO REG4
         AR    4,7            ADD THIS EMP STATE WH TO THE TOTAL
         ST    4,STWHT        STORE THE NEW TOTAL              
*                                                              
         SR    3,5            SUBTRACT FEDWH FROM GROSS PAY    
         SR    3,7            SUBTRACT STATEWH FROM GROSS PAY  
*                                                              
         XDECO 3,ONETPAY      DISPLAY NET PAY                  
*                                                              
         L     4,NETT         LOAD THE TOTAL PAY INTO REG 4    
         AR    4,3            ADD THIS EMP TOTAL PAY TO THE TOTAL
         ST    4,NETT         STORE THE NEW TOTAL              
*                                                              
         C     8,=F'16'       COMPARE REG8 TO 16               
LOOP2    BC    B'1101',ENDLOOP2  BRANCH TO ENDLOOP 2 IF CND NOT MET
*                                                              
         LA    9,1(,9)        INCREMENT THE PAGE COUNTER       
         XDECO 9,TEMP         GET PAGE COUNT INTO TEMP STRG    
         MVC   OPAGE(2),TEMP+10 MOVE USEFUL BYTES              
*                                                              
         XPRNT HEADER1,133    PRINT PAGE COUNTER               
         XPRNT COLHDR1,133    PRINT COL HEADER1                
         XPRNT COLHDR2,133    PRINT COL HEADER2                
         XPRNT HYPHENS1,133   PRINT HYPHENS                    
*                                                              
         SR    8,8            SET LINE COUNTER BACK TO 0       
ENDLOOP2 DS    0H                                                
*                                                              
         XPRNT DETAIL,133     PRINT THE EMPLOYEE DETAIL RECORD 
*                                                              
         XREAD RECORD,80      READ NEXT EMPLOYEE RECORD        
*                                                              
         BC    B'1111',LOOP1  BRANCH TO TOP OF LOOP1 TO CHECK EOF
*                                                              
ENDLOOP1 DS    0H                                                
*                                                              
         L     4,EMPNUM       LOAD REG4 WITH NUM OF EMP        
         XDECO 4,OEMPNUM      DISPLAY NUM OF EMP               
*                                                              
         L     4,GROSST       LOAD REG4 WITH GROSS TOTAL       
         XDECO 4,OGROSST      DISPLAY GROSS TOTAL              
*                                                              
         L     4,FEDWHT       LOAD FED WITHHOLDING TOTAL INTO REG4
         XDECO 4,OFEDWHT      DISPLAY FED WITHHOLDING TOTAL    
*                                                              
         L     4,STWHT        LOAD STATE WITHHOLDING TOTAL INTO REG4
         XDECO 4,OSTWHT       DISPLAY STATE WITHHOLDING TOTAL  
*                                                              
         L     4,NETT         LOAD NET PAY TOTAL INTO REG 4    
         XDECO 4,ONETT        DISPLAY NET PAY TOTAL            
*                                                              
         XPRNT HYPHENS2,133   PRINT HYPHEN LINE 2              
         XPRNT TOTALS1,133    PRINT TOTALS LINE                
         BCR   B'1111',14     UNCONDITIONAL RETURN TO CALLER   
*                                                              
         LTORG                LITERAL ORGANIZATION             
         =F'100'                                             
         =F'16'                                               
*                                                              
TEMP     DS    CL10           TEMP STORAGE FOR PAGE COUNT      
EMPNUM   DC    F'0'           STORAGE FOR NUM OF EMPLOYEES     
GROSST   DC    F'0'           STORAGE FOR TOTAL GROSS PAY      
FEDWHT   DC    F'0'           STORAGE FOR TOTAL FED WH         
STWHT    DC    F'0'           STORAGE FOR TOTAL STATE WH       
NETT     DC    F'0'           STORAGE FOR TOTAL NET PAY        
*                                                              
* THE FOLLOWING 16 LINES ARE THE DEFINITION FOR THE OUTPUT DETAIL
*   LINE FOR EACH EMPLOYEE FOR THE REPORT YOU ARE CREATING.  IT 
*   IS EXACTLY 133 BYTES LONG.  EACH OUTPUT FIELD IS SEPARATED 
*   BY 4 OR 5 BYTES OF EBCDIC SPACES, i.e., X'40'.              
*                                                              
DETAIL   DC    C'0'   CARRIAGE CONTROL CHARACTER               
OEMPNME  DS    CL25   OUTPUT FIELD FOR EMPLOYEE NAME           
          DC    4C' '  SPACES                                 
OEMPID   DS    CL5    OUTPUT FIELD FOR EMPLOYEE ID             
          DC    4C' '  SPACES                                 
OPAYRATE DS    CL12   OUTPUT FIELD FOR XDECO OF PAY RATE       
          DC    4C' '  SPACES                                 
OHOURS   DS    CL12   OUTPUT FIELD FOR XDECO OF HOURS WORKED   
          DC    4C' '  SPACES                                 
OGROSS   DS    CL12   OUTPUT FIELD FOR XDECO OF GROSS PAY AMT  
          DC    4C' '  SPACES                                 
OFEDWH   DS    CL12   OUTPUT FIELD FOR XDECO OF FEDERAL WH AMT 
          DC    5C' '  SPACES                                 
OSTWH    DS    CL12   OUTPUT FIELD FOR XDECO OF STATE WH AMT   
          DC    5C' '  SPACES                                 
ONETPAY  DS    CL12   OUTPUT FIELD FOR XDECO OF NET PAY AMT    
*                                                              
TOTALS1  DC    C'0'       CARRIAGE CONTROL CHARACTER           
          DC    C'NUMBER OF EMPLOYEES:' LABEL                 
          DC    CL2' '    SPACES                              
OEMPNUM  DS    CL3        OUTPUT FIELD FOR EMPNUM              
          DC    34C' '     SPACES                              
          DC    C'TOTALS:' LABEL                              
          DC    CL4' '     SPACES                              
OGROSST  DS    CL12       OUTPUT FIELD FOR GROSS TOTAL         
          DC    4C' '      SPACES                              
OFEDWHT  DS    CL12       OUTPUT FIELD FOR FED WH TOTAL        
          DC    5C' '      SPACES                              
OSTWHT   DS    CL12       OUTPUT FIELD FOR STATE WH TOTAL      
          DC    5C' '      SPACES                              
ONETT    DS    CL12       OUTPUT FIELD FOR NET TOTAL           
*                                                              
HEADER1  DC    C'0'       CARRIAGE CONTROL CHARACTER           
          DC    53C' '     SPACES                             
          DC    CL27'SEMI-MONTHLY PAYROLL REPORT'             
          DC    43C' '     SPACES                             
          DC    C'PAGE:  ' LABEL                              
OPAGE    DS    CL1        OUTPUT FIELD FOR PAGE NUMBER         
*                                                              
COLHDR1  DC    C'0'       CARRIAGE CONTROL CHARACTER           
          DC    91C' '     SPACES                             
          DC    C'FEDERAL' LABEL                              
          DC    12C' '     SPACES                             
          DC    C'STATE'   LABEL                              
          DC    11C' '     SPACES                             
          DC    C'DIRECT'  LABEL                              
*                                                              
COLHDR2  DC    C'0'       CARRIAGE CONTROL CHARACTER           
          DC    C'EMPLOYEE NAME' LABEL                        
          DC    19C' '     SPACES                             
          DC    C'ID'      LABEL                              
          DC    7C' '      SPACES                             
          DC    C'HOURS PAY'  LABEL                           
          DC    4C' '      SPACES                             
          DC    C'HOURS WORKED'    LABEL                      
          DC    7C' '      SPACES                             
          DC    C'GROSS PAY'       LABEL                      
          DC    5C' '      SPACES                             
          DC    C'WITHHOLDING'     LABEL                      
          DC    6C' '      SPACES                             
          DC    C'WITHHOLDING'     LABEL                      
          DC    6C' '      SPACES                             
          DC    C'DEPOSIT AMT'     LABEL                      
*                                                              
HYPHENS1 DC    C'0'         CARRIAGE CONTROL CHARACTER         
          DC    26C'-'       HYPHENS                          
          DC    4C' '        SPACE                            
          DC    4C'-'        HYPHENS                          
          DC    4C' '        SPACE                            
          DC    12C'-'       HYPHENS                          
          DC    4C' '        SPACE                            
          DC    12C'-'       HYPHENS                          
          DC    4C' '        SPACE                            
          DC    12C'-'       HYPHENS                          
          DC    4C' '        SPACE                            
          DC    12C'-'       HYPHENS                          
          DC    5C' '        SPACE                            
          DC    12C'-'       HYPHENS                          
          DC    5C' '        SPACE                            
          DC    12C'-'       HYPHENS                          
*                                                              
HYPHENS2 DC    C'0'      CARRIAGE CONTROL CHARACTER           
          DC    CL70' '   SPACES                              
          DC    12C'-'    HYPHENS                             
          DC    4C' '     SPACE                               
          DC    12C'-'    HYPHENS                             
          DC    5C' '     SPACE                               
          DC    12C'-'    HYPHENS                             
*                                                              
*  THE FOLLOWING IS THE BUFFER FOR THE INPUT RECORD            
*                                                              
RECORD   DS    CL80   BUFFER FOR EMPLOYEE RECORD READ FROM INPUT FILE
*                                                              
 END   ASSIGN7
