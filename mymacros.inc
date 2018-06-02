freezeP MACRO freeze ,oldC,oldT ,Pclr  
		 
		 Gettime 
 		 mov oldT,dh 
		 
		 mov  bl ,1
		 mov freeze,bl
         
		 mov bl , Pclr
		 mov oldC , bl
			
		 mov bl , Fclr 
		 mov Pclr ,bl
		
ENDM freezeP1
;--------------------------------------
checkmaze MACRO clr
local loop1
local loop2
local endin
local endin2

mov bh , 0
mov bl , 0

loop1:	

	 
	
	push cx
	mov bh,0
	
	loop2:
	
		mov ah,0DH		
		int 10h
		cmp al,	clr
		jz endin 
	
	
		inc cx
		inc bh
		
		cmp bh , 3
	jnz loop2

	pop cx
	
	inc bl
	inc dx
	
	cmp bl , 7
	jnz loop1
	
	jmp endin2
	
	endin:
		pop cx
		mov bl,1
	endin2:
	
ENDM check

;-------------------------------------------------
checkplayer1 MACRO

	
		cmp al , 77h
        jz up  
        
        cmp al , 73h
        jz down
        
        cmp al , 61h
        jz left
        
        cmp al , 64h
        jz right
		
		
	;-------- Shooting Keys 	---------
		
		cmp al, 57h
		jz shootup
        
		cmp al,53h
		jz shootdown

		cmp al, 41h
		jz shootleft

		cmp al,44h
		jz shootright
		
	;------------------------------------
        
        jmp player2 
        
        up:  
	
			mov dx , player1Y
			sub dx,3
			mov cx,player1X
			checkmaze mclr
			cmp bl , 1
			jz game
			
			
			mov dx , player1Y
			sub dx,3
			mov cx,player1X
			checkmaze cpClr
			cmp bl , 1
			jz changing1
			

			mov dx , player1Y
			sub dx,3
			mov cx,player1X
			checkmaze flag1clr
			cmp bl,1
			jz gotFlag1
			
			mov dx , player1Y
			sub dx,3
			mov cx,player1X			
			checkmaze Fclr
			
			cmp bl , 1
			jnz moveUp1
			
			freezeP freeze1,oldC1,oldT1,clr1
			
			mov dx , player1Y
			sub dx,3
			mov cx,player1X
			clearTrap
			
			mov dx , player1Y
			sub dx,3
			mov cx,player1X
			
	
	
	;		jnz gotFlag1
	;			gotflag1p
				;jmp gameending
			
			
			
			moveUp1:
				
				drawplayer player1X,player1Y,delete
				mov ax , 3
				sub player1Y,ax
				
			jmp game       
                  
     down:   
			mov dx , player1Y
			add dx,3
			mov cx,player1X
			
			
			checkmaze mclr
			cmp bl , 1
			jz game
		
			mov dx , player1Y
			add dx,3
			mov cx,player1X
			checkmaze cpClr
			cmp bl , 1
			jz changing1
			
			
			mov dx , player1Y
			add dx,3
			mov cx,player1X
			checkmaze flag1clr
			cmp bl,1
			jz gotFlag1
			
			mov dx , player1Y
			add dx,3
			mov cx,player1X			
			checkmaze Fclr
			cmp bl , 1
			jnz moveDown1
			freezeP freeze1,oldC1,oldT1,clr1
			
			
			mov dx , player1Y
			add dx,3
			mov cx,player1X	
			clearTrap
			
			moveDown1:
			
				drawplayer player1X,player1Y,delete
				mov ax , 3
				add player1Y,ax
            
			jmp game 
        
        right:  

			mov dx , player1Y
			mov cx,player1X
			add cx,3
			checkmaze mclr
			cmp bl , 1
			jz game
			
			mov dx , player1Y
			mov cx,player1X
			add cx,3
			checkmaze cpClr
			cmp bl , 1
			jz changing1

			mov dx , player1Y
			mov cx,player1X
			add cx,3
			checkmaze flag1clr
			cmp bl,1
			jz gotFlag1
			
			mov dx , player1Y
			mov cx,player1X
			add cx,3		
			checkmaze Fclr
			cmp bl , 1
			jnz moveRight1
			freezeP freeze1,oldC1,oldT1,clr1
			
			mov dx , player1Y
			mov cx,player1X
			add cx,3
			clearTrap
			
			
			moveRight1:
			
            drawplayer player1X,player1Y,delete
            mov ax , 3
            add player1X,ax
            
			jmp game 
        
  left:    
			mov dx , player1Y
			mov cx,player1X
			sub cx,3
			checkmaze mclr
			cmp bl , 1
			jz game
			
			mov dx , player1Y
			mov cx,player1X
			sub cx,3
			checkmaze cpClr
			cmp bl , 1
			jz changing1
			
			
			mov dx , player1Y
			mov cx,player1X
			sub cx,3
			checkmaze flag1clr
			cmp bl,1
			jz gotFlag1
			
			
			mov dx , player1Y
			mov cx,player1X
			sub cx,3		
			checkmaze Fclr
			cmp bl , 1
			jnz moveLeft1
			freezeP freeze1,oldC1,oldT1,clr1
			
			
			mov dx , player1Y
			mov cx,player1X
			sub cx,3		
			clearTrap
			
			
			moveLeft1:

			drawplayer player1X,player1Y,delete
            mov ax , 3
            sub player1x,ax
            
			jmp game 
			
			
			changing1:
			    drawplayer player1X,player1Y,delete
				mov bx,30
				mov player1X,bx
				mov bx,39
				mov player1Y,bx
			jmp game
			
			gotFlag1:
				gotFlag1p p1win,clr1,player1X,player1Y
				jmp gameending
			
			shootup:
				shootup player1X,player1Y,kill
				cmp bl,10
			jne end
				drawplayer player2X,player2Y,delete
				mov player2X,30
				mov player2Y,60
				mov bl,0
				jmp game
				
			shootdown:      
				shootdown player1X,player1Y,kill
				cmp bl,10
			jne end
				drawplayer player2X,player2Y,delete
				mov player2X,30
				mov player2Y,60
				mov bl,0
			jmp game   

			shootleft:      
				shootleft player1X,player1Y,kill
				cmp bl,10
			jne end
				drawplayer player2X,player2Y,delete
				mov player2X,30
				mov player2Y,60
				mov bl,0
				jmp game  

			shootright:      
				shootright player1X,player1Y,kill
				cmp bl,10
			jne end
				drawplayer player2X,player2Y,delete
				mov player2X,30
				mov player2Y,60
				mov bl,0
			jmp game           


			end:
			mov bl,0
			jmp game
			
			
			
ENDM checkplayer1
;--------------------------------------
checkplayer2 MACRO
local changing
	    
		cmp al , 69h
        jz up2  
        
        cmp al , 6Bh
        jz down2
        
        cmp al , 6Ah
        jz left2
        
        cmp al , 6Ch
        jz right2
			
		;--------- Shooting Keys -------------
		
		cmp al, 49h
		jz shootup2
        
		cmp al,4Bh
		jz shootdown2

		cmp al,4Ah
		jz shootleft2

		cmp al,4Ch
		jz shootright2
		
		;-------------------------------------
		
			
        jmp cont
        
        up2:  
		
			mov dx , player2Y
			sub dx,3
			mov cx,player2X
			checkmaze mclr
			cmp bl , 1
			jz game
			
			mov dx , player2Y
			sub dx,3
			mov cx,player2X
			checkmaze cpClr
			cmp bl , 1
			jz changing2
			
			mov dx , player2Y
			sub dx,3
			mov cx,player2X
			checkmaze flag1clr
			cmp bl,1
			jz gotFlag2
			
			mov dx , player2Y
			sub dx,3
			mov cx,player2X			
			checkmaze Fclr
			
			cmp bl , 1
			jnz moveUp2
			freezeP freeze2,oldC2,oldT2,clr2
			
			mov dx , player2Y
			sub dx,3
			mov cx,player2X		
			clearTrap

			
			moveUp2:
			
				drawplayer player2X,player2Y,delete
				mov ax , 3
				sub player2Y,ax
				
			jmp game       
                  
     down2:   
			mov dx , player2Y
			add dx,3
			mov cx,player2X
			checkmaze mclr
			cmp bl , 1
			jz game
			
			mov dx , player2Y
			add dx,3
			mov cx,player2X
			checkmaze cpClr
			cmp bl , 1
			jz changing2
		

			mov dx , player2Y
			add dx,3
			mov cx,player2X
			checkmaze flag1clr
			cmp bl,1
			jz gotFlag2
			
			mov dx , player2Y
			add dx,3
			mov cx,player2X			
			checkmaze Fclr
			
			cmp bl , 1
			jnz moveDown2
			freezeP freeze2,oldC2,oldT2,clr2
			
			
			mov dx , player2Y
			add dx,3
			mov cx,player2X	
			clearTrap
			
			moveDown2:
			
			
				drawplayer player2X,player2Y,delete
				mov ax , 3
				add player2Y,ax
            
			jmp game 
        
        right2:  

			mov dx , player2Y
			mov cx,player2X
			add cx,3
			checkmaze mclr
			cmp bl , 1
			jz game
			 
			mov dx , player2Y
			mov cx,player2X
			add cx,3 
			checkmaze cpClr
			cmp bl , 1
			jz changing2


			mov dx , player2Y
			mov cx,player2X
			add cx,3
			checkmaze flag1clr
			cmp bl,1
			jz gotFlag2
			
			mov dx , player2Y
			mov cx,player2X
			add cx,3 			
			checkmaze Fclr
			
			cmp bl , 1
			jnz moveRight2
			freezeP freeze2,oldC2,oldT2,clr2
			
			
			mov dx , player2Y
			mov cx,player2X
			add cx,3 
			clearTrap
			
			moveRight2:
			
				drawplayer player2X,player2Y,delete
				mov ax , 3
				add player2X,ax
				
			jmp game 
        
  left2:    
			mov dx , player2Y
			mov cx,player2X
			sub cx,3
			checkmaze mclr
			cmp bl , 1
			jz game
			
			mov dx , player2Y
			mov cx,player2X
			sub cx,3
			checkmaze cpClr
			cmp bl , 1
			jz changing2
			

			mov dx , player2Y
			mov cx,player2X
			sub cx,3
			checkmaze flag1clr
			cmp bl,1
			jz gotFlag2
			
			
			mov dx , player2Y
			mov cx,player2X
			sub cx,3 			
			checkmaze Fclr
			
			cmp bl , 1
			jnz moveLeft2
			freezeP freeze2,oldC2,oldT2,clr2
			
			mov dx , player2Y
			mov cx,player2X
			sub cx,3 
			clearTrap
			
			moveLeft2:
				
				drawplayer player2X,player2Y,delete
				mov ax , 3
				sub player2x,ax
				
        jmp game 
		
		changing2:
			    drawplayer player2X,player2Y,delete
				mov bx,30
				mov player2X,bx
				mov bx,60
				mov player2Y,bx
			jmp game
            
			
			gotFlag2:
				gotFlag2p p2win,clr2,player2X,player2Y
				
			jmp gameending

		shootup2:
			shootup player2X,player2Y,kill
			cmp bl,10
			jne end2
			drawplayer player1X,player1Y,delete
			mov player1X,30
			mov player1Y,39
			mov bl,0
			jmp game

		shootdown2:      
			shootdown player2X,player2Y,kill
			cmp bl,10
			jne end2
			drawplayer player1X,player1Y,delete
			mov player1X,30
			mov player1Y,39
			mov bl,0
			jmp game  

		shootleft2:      
			shootleft player2X,player2Y,kill
			cmp bl,10
			jne end2
			drawplayer player1X,player1Y,delete
			mov player1X,30
			mov player1Y,39
			mov bl,0
			jmp game

		shootright2:      
			shootright player2X,player2Y,kill
			cmp bl,10
			jne end2
			drawplayer player1X,player1Y,delete
			mov player1X,30
			mov player1Y,39
			mov bl,0
			jmp game             


		end2:
			mov bl,0
			jmp game


		
		
ENDM checkplayer2
;--------------------------------------

Gettime MACRO
	push ax

	mov ah,2ch
	int 21h
	
	pop ax

ENDM Gettime


;--------------------------------------
;Macros for TextMode

 clear macro 
       ;clear screen
       mov ax,0600h
       mov bh,07
       mov cx,0
       mov dx,184fh
       int 10h
 endm
 
 
 display macro msg 
       ;display  
       mov ah,9
       mov dx,offset msg
       int 21h
 endm

 displayphrase macro msg 
       ;display  
	   mov ah,0   ;..change to textmode
				  int 10h    
				  mov ah,02 
				  mov al,00
				  mov bh,00
				  mov dh,0 ; .. print phrase ;cursor1y
				  mov dl,22 ;cursor 1x
				  int 10h 
       mov ah,9
       mov dx,offset msg
       int 21h
 endm
 
 movecursor macro x,y
       ;move cursor
       mov ah,2 
       mov bh,0
       mov dl,x
       mov dh,y  
      
       int 10h
 endm 