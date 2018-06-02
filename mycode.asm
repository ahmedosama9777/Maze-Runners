.model long
.stack 32
.data 
 
 
include mymacros.inc                
include draw.inc
include shooting.inc
include bar.inc
 ;-----Main menu data------------------------------------------------------------------------------------

player1N db 15,?,15 dup('$')   
player2N db 15,?,15 dup('$')
p1wingame db 'Player1 wins','$' 
p2wingame db 'Player2 wins','$' 


scoremsg db "'s score : $"



msg1 db 'Please enter your name (P1): ','$'
msg12 db 'Please enter your name (P2): ','$'
msg3 db 'Re enter your name: $'

msg4 db '*To start chatting press 1','$'
msg5 db '*To start the game press 2','$'
msg6 db '*To end the program press ESC ','$'

mge1 db " Instructions $"

mge2 db "1)There are 5 brown Flags ,you need to pick 3 of them to win .$"
               
mge3 db "2)Walk carfully, There are many traps you could fall into them .$"
               
mge4 db "3)When you shoot the other player , he starts from the beggining again.$"
         
mge5 db "4)controls =>w,s,a,d directions for player1.(shift +direction) to shoot.$"
          
mge6 db "5)controls =>i,k,l,j directions for player2.(shift +direction) to shoot.$"                        

mge7 db "Press any key to continue. $"



;----------------------------------- 
                         
   Fclr db 0Bh,"$"
   mclr db 10,"$" 
   cpClr db 0Dh,"$"
   delete db 00h ,"$" 

 ;Flag Data
flag1X dW  260,?
flag1Y dW  73,?
flag1clr db 06h,?
;--------------
p1win db 0,?
p2win db 0 ,?
winclr db 1h,?


;------------- 
   
   
kill db 0 ,"$"
;Player 2 Data 
   
player2X dw 30,"$"
player2Y dw 60,?
clr2 db 0Ch,"$"
; Some data required for freezing trap 
freeze2 db 0 ,?  ;check if he is freezed
oldT2 db ?,"$"
oldC2 db ?,"$"
IN2   db ?,"$"

;-------------------------------------                 
;player 1 data                 
player1X dW 30,"$"                                      
player1Y dW 39,?
clr1 db 0Eh ,"$"
; Some data required for freezing trap 
freeze1 db 0 ,?
oldT1 db ?,"$"
oldC1 db ?,"$"
IN1   db ?,"$"

;-------------------------------------

;Freeze Trap data
trapX dW 30,"$"
trapY dW 24,? 
;-----------------
cpX dw 232
cpY dw 69

  

.code 
main    proc FAR
        mov ax,@data
        mov ds,ax
 
 ;==================Text Mode  ==========================
         
        mov ah,0 
        mov al,03h
        int 10h 

    ;----display msg2
    
        movecursor 0,0                                                                                               
        
        display msg1
               
                      
    ;-----keyboard
    back:
     
        mov ah,07;read char
        int 21h
     
                 
        cmp al ,61h;less than a
        jb error
        cmp al,7ah;more than z
        jb display1
        
                      
    error:
       
        clear;clear screen
        
       
        movecursor 0,0;
        display msg3
        jmp back 
       

    display1:
    
        ;--- Display the pressed character ---
        mov ah,2
        mov dl,al
        int 21h
        

          mov player1N,al
        mov si , offset player1N+1
       
       readname:
        mov ah,07
        int 21h       ;read without display
         
        cmp al,0Dh;check if it's enter key 
        jz cont6     
         
        ;--- Display the pressed character --- 
        mov ah,2
        mov dl,al
        int 21h
        ;-------------------------------------
        mov [si] , al
        inc si
        jmp readname
;-----------------------------------------READ(P2)NAME-----------------------------------
   cont6: 
   clear                                                                   
     ;----display msg2
    
        movecursor 0,0                                                                                               
        
        display msg12
        
                      
    ;-----keyboard
    back2:
     
        mov ah,07;read char
        int 21h
     
                 
        cmp al ,61h;less than a
        jb error2
        cmp al,7ah;more than z
        jb display2
        
                      
    error2:
       
        clear;clear screen
        
       
        movecursor 0,0  ;bet7rk leh 
        display msg3
        jmp back2 
       

    display2:
    
        ;--- Display the pressed character ---
        mov ah,2
        mov dl,al
        int 21h
        

        mov player2N,al
        mov si , offset player2N+1
       
       readname2:
        mov ah,07
        int 21h       ;read without display
         
        cmp al,0Dh;check if it's enter key 
        jz cont4     
         
        ;--- Display the pressed character --- 
        mov ah,2
        mov dl,al
        int 21h
        ;-------------------------------------
        mov [si] , al
        inc si
        jmp readname2                                                                      
                                                                       
;--------------------------------------MainMenu--------------------------------------        
         
         
       cont4:      
          
        ;clear screen
        clear
        
        ;----display msg4
        movecursor 25,10
        
        display msg4
        
        ;----display msg5
        movecursor 25,12
        
        display msg5
                                                                                          
        ;----display msg6
        
        movecursor 25,14
        
        display msg6
;--------------------------------------------------------------------------------------------------------------        
Mainscreen:    
        mov ah,0
        int 16h
        cmp ah,01h;wait for ESC
        je ending2
        cmp al,31h;wait for (1)
        ;je chat
        cmp al,32h;wait for (2)
        je instructions
        jmp Mainscreen
        
                            
        ;esc 01h , f1 3bh , f2 3ch          
        instructions:
			clear 
            
            movecursor 30,1
            display mge1 
            movecursor 1,3
            display mge2
            movecursor 1,5
            display mge3
            movecursor 1,7
            display mge4
            movecursor 1,9
            display mge5
            movecursor 1,11
            display mge6   
            movecursor 23,14
            display mge7
		
		 mov ah, 0   ; get the key
         int 16h
        
;==================Video mode========================       
 
      startgame:
 
 
        mov ah,0 
        mov al,13h                       
        INT 10h
 	
        
         drawmaze
		 
		 
         drawtrap trapX,trapY,Fclr
		 
         mov bx ,228
		 mov trapX,bx
		 mov bx,24
		 mov trapY,bx
		 drawtrap trapX,trapY,Fclr

		 
		 mov bx ,30
		 mov trapX,bx
		 mov bx,143
		 mov trapY,bx
		 drawtrap trapX,trapY,Fclr
		 
		 mov bx ,42
		 mov trapX,bx
		 mov bx,49
		 mov trapY,bx
		 drawtrap trapX,trapY,Fclr
		
		
		 mov bx ,228
		 mov trapX,bx
		 mov bx,24
		 mov trapY,bx
		 drawtrap trapX,trapY,Fclr
		 
		 
		 mov bx ,131
		 mov trapX,bx
		 mov bx,4
		 mov trapY,bx
		 drawtrap trapX,trapY,Fclr
		 

		 
		  mov bx ,227
		 mov trapX,bx
		 mov bx,67
		 mov trapY,bx
		 drawtrap trapX,trapY,Fclr
		 
		  mov bx ,136
		 mov trapX,bx
		 mov bx,80
		 mov trapY,bx
		 drawtrap trapX,trapY,Fclr
		
		
		 
         drawtrap cpX,cpY,cpClr
		 
         mov bx ,87
		 mov cpX,bx
		 mov bx,67
		 mov cpY,bx
		 drawtrap cpX,cpY,cpClr
		
	     mov bx ,50
		 mov cpX,bx
		 mov bx,106
		 mov cpY,bx
		 drawtrap cpX,cpY,cpClr
		 

		  mov bx ,213
		 mov cpX,bx
		 mov bx,67
		 mov cpY,bx
		 drawtrap cpX,cpY,cpClr
		 
		  mov bx ,267
		 mov cpX,bx
		 mov bx,11
		 mov cpY,bx
		 drawtrap cpX,cpY,cpClr
		 
		  mov bx ,140
		 mov cpX,bx
		 mov bx,80
		 mov cpY,bx
		 drawtrap cpX,cpY,cpClr      
		 
		
		 mov bx ,82
		 mov cpX,bx
		 mov bx,80
		 mov cpY,bx
		 drawtrap cpX,cpY,cpClr
		 
		  mov bx ,59
		 mov cpX,bx
		 mov bx,59
		 mov cpY,bx
		 drawtrap cpX,cpY,cpClr
		         
		         
		         
		 drawflag flag1X,flag1Y
         
         mov bx , 142
         mov flag1Y , bx
                     
                     
         mov bx , 265
         mov flag1X , bx
         
         drawflag flag1X,flag1Y
         
          
         mov bx , 81
         mov flag1Y , bx
                     
                     
         mov bx , 136
         mov flag1X , bx
         
         drawflag flag1X,flag1Y
          
          
               
       
        movecursor 0,21; 
        display  player1N 
        display scoremsg
                      
                         
        movecursor 0,23;
        display  player2N
        display scoremsg    
      
      game:
        
        ;------------------------------             
       
   
        ;------------------------------
        drawplayer player1X,player1Y,clr1   ;drawig
        drawplayer player2X,player2Y,clr2         
       
       cont: 
            mov al , 0  
			mov ah,01h ;waiting for key to be presssed        
            int 16h
            jz player1
          
         mov ah, 0   ; get the key
         int 16h    
         
       player1:
          
         cmp freeze1, 1 
         jnz  cont1
		 
		 mov IN1,al
		 mov IN2,ah
		 
         Gettime 
         mov al,IN1
		 mov ah,IN2
		 
		 mov ch , oldT1
		 
		 
         cmp dh,ch
         JL   checktime
         sub dh,ch
          
   AGAIN:
    
         cmp dh,5
         js player2

         mov dl,0
         mov freeze1,dl
		 mov bl , oldC1
		 mov clr1,bl
		 drawplayer player1X,player1Y,clr1
		 mov al,IN1	
		 mov ah,IN2
         jmp cont1

   checktime:
    
       add dh,60 
       sub dh,ch    
       jmp AGAIN 
       
    cont1:
    
          checkplayer1    ; Updating Player 1
        
     
       player2: 
        
        
		 cmp freeze2, 1 
         jnz  cont2
		 
		 mov IN2,ah
		 
         Gettime 
         mov ah,IN2
		 
		 
		 mov ch , oldT2
		 
		 
         cmp dh,ch
         JL   checktime2
         sub dh,ch
          
	   AGAIN2: 
			  
			 cmp dh,5
			 js game

			 mov dl,0
			 mov freeze2,dl
			 mov bl , oldC2
			 mov clr2,bl
			 drawplayer player2X,player2Y,clr2       
		     mov ah,IN2
		  	 jmp cont2

	   checktime2:
		
		   add dh,60 
		   sub dh,ch    
		   jmp AGAIN2 
       
    cont2: 
    
        checkplayer2   ; Updating Player 2
                                   
       
      jmp game  

		;--------------------------------------------------------------------------------
		
				
			gameending:
				  endgame 
				  mov al,p1win
				  cmp al,1
				  je p1wins
				  mov ah,p2win 
				  cmp ah,1
				  je p2wins
				  p1wins:
				 mov ah,0   ;..change to textmode
				  int 10h    
				  mov ah,02 
				  mov al,00
				  mov bh,00
				  mov dh,10 ; .. print phrase 
				  mov dl,10 
				  int 10h 
				 mov ah,9
				 mov dx,offset player1N
				 int 21h  
				 jmp gameover   
				 p2wins:
				  mov ah,0   ;..change to textmode
				  int 10h    
				  mov ah,02 
				  mov al,00
				  mov bh,00
				  mov dh,10 ; .. print phrase 
				  mov dl,10 
				  int 10h 
				 mov ah,9
				 mov dx,offset player2N
				 int 21h 
		  gameover:
				
				
		;--------------------------------------------------------------------------------

    ending2:         
    
        endm
    
    
    
main endp         