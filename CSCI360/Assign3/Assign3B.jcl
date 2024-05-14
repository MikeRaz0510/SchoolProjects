//KC03E54A JOB ,'M.RASMUSSEN',MSGCLASS=H
//JSTEP01  EXEC PGM=ASSIST
//STEPLIB  DD DSN=KC00NIU.ASSIST.LOADLIB,DISP=SHR
//SYSPRINT DD SYSOUT=*
//SYSIN    DD *
//
***************************************************************
*                                                             *
* CSCI 360-PE1 ASSIGNMENT 3                      Spring 2023  *
*                                                             *
* PROGRAMMER NAME: Mike Rasmussen                             *
*                                                             *
* DATE: 2/17/23                                               *
*                                                             *
* PROGRAM NAME: ASSIGN3B                                      *
*                                                             *
* FUNCTION: Subtract 2 registers and store the answer         *
*                                                             *
***************************************************************
*                                                             
ASSIGN3B CSECT                                                 
         USING ASSIGN3B,15 Establish addressability on reg 15  
         L     2,NUM1      Load NUM1 into reg 2                
         L     3,NUM2      Load NUM2 into reg 3                
         SR    2,3         Subtract reg 3 val from reg 2 val   
         ST    2,ANSWER    Store the Answer                    
         XDUMP ANSWER,4    Dump value of the answer            
         BCR   B'1111',14  Unconditional return to caller (os) 
*                                                             
         LTORG             Literal organization                
NUM1     DC    F'15'       NUM1 = 15                           
NUM2     DC    F'7'        NUM2 = 7                            
ANSWER   DC    F'0'        ANSWER Initilized to 0              
*                                                             
         END   ASSIGN3B
