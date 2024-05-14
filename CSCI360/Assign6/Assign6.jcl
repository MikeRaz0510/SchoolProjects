//KC03E54A JOB ,'M.Rasmussen',MSGCLASS=H
//JSTEP01  EXEC PGM=ASSIST
//STEPLIB  DD DSN=KC00NIU.ASSIST.LOADLIB,DISP=SHR
//SYSPRINT DD SYSOUT=*
//SYSIN    DD *
*****************************************************************
*                                                               *
* CSCI 360-PE1           ASSIGNMENT 6               Spring 2023 *
* MULTIPLICATION & DIVISION                                     *
*                                                               *
* DEVELOPER NAME: Mike Rasmussen                                *
* DUE DATE: 3/24/23                                             *
*                                                               *
*****************************************************************
*                                                              
ASSIGN6  CSECT                                                  
         USING ASSIGN6,15     ESTABLISH ADDRESSABILITY ON REG 15
*                                                              
         LA    10,16          GET FED WITHHOLDING PERCENT INTO R10
         LA    11,4           GET STATE WITHHOLDING PERCENT INTO R11
*                                                              
         XREAD RECORD,80      GET FIRST EMPLOYEE RECORD        
*                                                              
LOOP1    BC   B'0100',ENDLOOP1  BRANCH TO ENDLOOP1 IF EOF       
*                                                              
*  HERE IS WHERE THE BODY OF YOUR LOOP WILL BE CODED           
*                                                              
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
         LR    5,3            COPY GROSS PAY FROM REG3 INTO REG5
         MR    4,10           MULTIPLY GROSS PAY BY FED TAX%   
         D     4,=F'100'      DIVIDE REG5 BY 100               
         XDECO 5,OFEDWH       DISPLAY FED WITHHOLDING          
*                                                              
         LR    7,3            COPY GROSS PAY FROM REG3 INTO REG7
         MR    6,11           MULTIPLY GROSS PAY BY STATE TAX%
         D     6,=F'100'      DIVIDE REG7 BY 100               
         XDECO 7,OSTWH        DISPLAY STATE WITHHOLDING        
*                                                              
         SR    3,5            SUBTRACT FEDWH FROM GROSS PAY    
         SR    3,7            SUBTRACT STATEWH FROM GROSS PAY  
*                                                              
         XDECO 3,ONETPAY      DISPLAY NET PAY                  
*                                                              
         XPRNT DETAIL,133     PRINT THE EMPLOYEE DETAIL RECORD 
*                                                              
         XREAD RECORD,80      READ NEXT EMPLOYEE RECORD        
*                                                              
         BC    B'1111',LOOP1  BRANCH TO TOP OF LOOP1 TO CHECK EOF
*                                                              
ENDLOOP1 DS    0H                                                
*                                                              
         BCR   B'1111',14     UNCONDITIONAL RETURN TO CALLER   
*                                                              
         LTORG                LITERAL ORGANIZATION             
*                                                              
         =F'100'                                             
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
*  THE FOLLOWING IS THE BUFFER FOR THE INPUT RECORD            
*                                                              
RECORD   DS    CL80   BUFFER FOR EMPLOYEE RECORD READ FROM INPUT FILE
*                                                              
 END   ASSIGN6
