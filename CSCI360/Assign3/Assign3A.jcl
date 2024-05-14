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
* PROGRAM NAME: ASSIGN3A                                      *
*                                                             *
* FUNCTION: Subtract 2 registers                              *
*                                                             *
***************************************************************
*                                                             
ASSIGN3A CSECT                                                 
         USING ASSIGN3A,15 ESTABLISH ADDRESSABILITY ON REG 15  
         L     2,NUM1      LOAD NUM1 INTO REG 2                
         L     3,NUM2      LOAD NUM2 INTO REG 3                
         SR    2,3         SUBTRACT REG 3 val from REG 2 val   
         XDUMP ,           DUMP CONTENTS OF ALL 16 REGS        
         BCR   B'1111',14  UNCONDITIONAL RETURN TO CALLER (OS) 
*                                                             
         LTORG             LITERAL ORGANIZATION                
NUM1     DC    F'15'       NUM1 = 15                           
NUM2     DC    F'7'        NUM2 = 7                            
*                                                             
         END   ASSIGN3A
