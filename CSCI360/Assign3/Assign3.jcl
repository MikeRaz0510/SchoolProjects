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
* PROGRAM NAME: ASSIGN3C                                      *
*                                                             *
* FUNCTION: Subtract 2 registers and store the answer using   *
*           explicit addressing                               *
*                                                             *
***************************************************************
*                                                             
ASSIGN3C CSECT                                                 
         USING ASSIGN3C,15 Establish addressability on reg 15  
         L     2,32(,15)   Load NUM1 into reg 2 with ExpAd     
         L     3,36(,15)   Load NUM2 into reg 3 with ExpAd     
         SR    2,3         Subtract reg 3 val from reg 2 val   
         ST    2,40(,15)   Store the answer with ExpAd         
         XDUMP ,           Dump all the Regs                   
         XDUMP 40(,15),4   Dump value of the answer            
*                          Dumping both ways because I dont    
*                          understand the wording in the assign
         BCR   B'1111',14  Unconditional return to caller (os) 
*                                                             
         LTORG             Literal organization                
         DC    F'15'       NUM1 = 15                           
         DC    F'7'        NUM2 = 7                            
         DC    F'0'        ANSWER Initilized to 0              
*                                                             
         END   ASSIGN3C
