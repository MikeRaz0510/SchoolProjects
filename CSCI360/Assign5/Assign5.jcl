//KC03E54A JOB ,'M.RASMUSSEN',MSGCLASS=H
//JSTEP01  EXEC PGM=ASSIST
//STEPLIB  DD DSN=KC00NIU.ASSIST.LOADLIB,DISP=SHR
//SYSPRINT DD SYSOUT=*
//SYSIN    DD *
//
*****************************************************************
*                                                               *
* CSCI 360-PE1           ASSIGNMENT 5               Spring 2023 *
* DISASSEMBLY & DECODING                                        *
*                                                               *
* DEVELOPER NAME: Mike Rasmussen                                *
* DUE DATE: 3/3/23                                              *
*                                                               *
* FILL IN CURRENT SEMESTER, DEVELOPER NAME AND DUE DATE.        *
*                                                               *
*****************************************************************
*                                                              
ASSIGN5 CSECT                                                  
         USING ASSIGN5,15 ESTABLISH ADDRESSABILITY ON REG 15    
*                                                              
         LA    4,23(,15)   Load register 4 with address of 23   
         L     5,60(,15)   Load register 5 with value at byte 60
*                                                              
         LR    2,4         Copy the contents of reg4 into reg2  
         AR    2,5         Add the contents of Reg5 to Reg2     
         ST    2,64(,15)   Store the contents of REG2 into byte 64
*                                                              
         LR    7,5         Copy the contents of Reg5 into Reg7  
         LR    6,4         Copy the contents of Reg4 into Reg6  
*                                                              
         MR    6,6         Multiply Reg7 by Reg6                
         ST    7,68(,15)   Store the contents of Reg7 into byte 68
*                                                              
         LR    9,4         Copy the contents of reg4 into reg9  
         M     4,80(,15)   Multiply reg5 by value at byte 80    
         DR    4,9         Divide Reg5 by Register 9            
*                                                              
         ST    4,72(,15)   Store the contents of Reg4 into byte 72
         ST    5,76(,15)   Store the contents of Reg5 into byte 76
*                                                              
         XDUMP ASSIGN5,84  Dump User storage                    
         BCR   B'1111',14  Unconditional return to caller (os)  
         LTORG             Literal organization                 
*                                                              
         DS    F                                              
         DC    F'101'      Byte 60                              
         DS    F           Byte 64                              
         DS    F           Byte 68                              
         DS    F           Byte 72                              
         DS    F           Byte 76                              
         DC    F'1'        Byte 80                              
*                                                              
 END ASSIGN5
