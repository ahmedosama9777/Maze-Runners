endgame macro
local loop1
local loop2
 mov bl,0
		    mov bh,0
			mov cx,0         ;Column 
			mov dx,0       ;Row       
			mov al,00       ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			loop2: int 10h
			inc cx
			cmp cx,800
		    je loop1
			cmp cx,800
		    jnz loop2
			loop1:
			inc dx
		    mov cx,0
			cmp dx,604
			jne loop2
endm endgame
;--------------------------------------
clearTrap MACRO 
local loop1
local loop2
		
		mov bl ,0
loop1:
		
		
		mov bh,0
		push cx
		
		loop2:
		
     
			mov al,delete       ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			int 10h
			inc cx
			inc bh 
			cmp bh,3
		
		jnz loop2
		
		pop cx 

		inc dx 
		
		inc bl
		cmp bl , 7
jnz loop1


ENDM clearTrap

;------------------------------------------
drawflag MACRO x,y

local loop1
local loop2
local loop4
		mov bl ,0
		mov cx , x
		mov dx , y
		
		
loop1:
		
		
		mov bh,0
		push cx
		
		loop2:
		
     
			mov al,06h       ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			int 10h
			inc cx
			inc bh 
			cmp bh,5
		
		jnz loop2
		
		pop cx 

		inc dx 
		
		inc bl
		cmp bl , 2
    jnz loop1
	
	
	mov bh , 0

	loop4:
		 
			mov al,06h        ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			int 10h
			inc dx

			
			inc bh 
			cmp bh,4
		
	jnz loop4
	
	

endm drawflag

;-------------------------------------------
drawtrap MACRO x,y,clr
local loop1
local loop2
mov bx, x
push bx
mov bx,y
push bx


mov ax , x
push ax


mov bl,0
loop1:
		
		mov bh,0
		
		loop2:
		
			mov cx,x         ;Column 
			mov dx,y        ;Row       
			mov al,clr       ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			int 10h
			inc x
			inc bh 
			cmp bh,1
		
		jnz loop2
		
		pop ax 
		mov x , ax 
		push ax 
		
		inc y		
		inc bl
		cmp bl , 1
    jnz loop1
pop bx
mov y,bx
pop bx
mov x,bx
ENDM drawtrap
;.....................................................

;-----------------------------------------------------

drawplayer MACRO x,y,clr
	
	local draw1
	local draw2
	local draw5
	local draw6
	local draw7
	local draw8
	local draw9
	local move
	local nomove
	
	
	mov bl , 0
	mov bh , 0

	mov ax , x
	mov cx , y
	
	push cx
	push ax
	
	
		draw1:
		
		mov bh,0
		
		draw2:
		
			mov cx,x         ;Column 
			mov dx,y        ;Row       
			mov al,clr        ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			int 10h
			inc x
			inc bh 
			cmp bh,3
		
		jnz draw2
		
		pop ax 
		mov x , ax 
		push ax 
		
		inc y		
		inc bl
		cmp bl , 3
    jnz draw1
	
	;------------------------------
	
	

	
	
	
	mov cx ,1
	add x , cx
	
	mov bx , y
	push bx 
	mov bx , x
	push bx
	
	mov bh ,0
		
	mov bx , y
	push bx 
	mov bx , x
	push bx
		
		
		draw8:
		
			mov cx,x         ;Column 
			mov dx,y        ;Row       
			mov al,clr        ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			int 10h
			inc y
			inc x
			inc bh 
			cmp bh,2
		
		jnz draw8
		
		pop bx 
		mov x , bx
		pop bx 
		mov y , bx
		
		
		mov bh , 0
		
		
		draw9:
		
			mov cx,x         ;Column 
			mov dx,y        ;Row       
			mov al,clr        ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			int 10h
			inc y
			dec x
			inc bh 
			cmp bh,2
		
		jnz draw9
	;------------------------------
	;------------------------------
	
	pop bx 
	mov x ,bx
	pop bx 
	mov y , bx 
	
	mov bh ,0
	
		draw5:
		
			mov cx,x         ;Column 
			mov dx,y        ;Row       
			mov al,clr        ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			int 10h
			inc y
			inc bh 
			cmp bh,2
		
		jnz draw5
		
		
		mov bx , y
		push bx
		mov bx , x
		push bx
		
		mov bh ,0
		
		
		draw6:
		
			mov cx,x         ;Column 
			mov dx,y        ;Row       
			mov al,clr        ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			int 10h
			inc y
			inc x
			inc bh 
			cmp bh,2
		
		jnz draw6
		
		pop bx 
		mov x , bx
		pop bx 
		mov y , bx
	
		mov bh , 0
		
		
		draw7:
		
			mov cx,x         ;Column 
			mov dx,y        ;Row       
			mov al,clr        ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			int 10h
			inc y
			dec x
			inc bh 
			cmp bh,2
		
		jnz draw7
			
	
	;-------------------------------
	pop ax 
	mov x , ax
	
	pop cx
	mov y,cx
	
	

ENDM drawplayer

;------------------------------------------------------
drh macro Posx,Posy,Length
local horizontal
mov cx,Posx ;Column
mov dx,Posy ;Row
mov bx,Length
mov al,10   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
horizontal: 
int 10h
inc cx
dec bx
cmp bx,0
jnz horizontal
endm drh
;------------------------------------------------------

drv macro Posx,Posy,Length
local vertical
mov cx,Posx ;Column
mov dx,Posy ;Row
mov bx,Length
mov al,10 ;Pixel color
mov ah,0ch ;Draw Pixel Command
vertical: 
int 10h
inc dx
dec bx
cmp bx,0
jnz vertical
endm drv

;------------------------------------------------------

drawmaze MACRO 

drv 25,0,150
drh 25,0,270  

drv 295,0,150
drh 25,150,270 

drv 35,10,20  
drh 35,30,10 
drv 45,30,10
drh 35,40,30
drv 35,40,30 
drv 65,40,10 
drh 35,70,10
drv 45,70,20
drh 25,80,10
drh 35,90,10
drh 25,100,10
drh 35,110,10
drv 45,90,30
drh 45,80,20
drh 25,120,10
drh 45,120,70
drv 35,120,10
drv 55,120,10
drv 95,120,10
drv 115,120,20
drh 35,130,10
drh 65,130,20
drv 45,130,10
drv 65,130,10
drv 85,130,10
drv 105,130,10
drh 35,140,30
drh 85,140,20
drv 75,140,10 
drh 45,10,20
drh 85,10,30
drh 135,10,30
drh 185,10,10
drh 225,10,10
drh 265,10,10
drv 45,10,10
drv 75,0,20
drv 125,0,20
drv 165,10,10  
drv 175,0,60
drv 185,10,20
drv 195,0,10
drv 205,10,10
drv 215,0,10
drv 225,10,10
drv 245,10,10 
drv 255,0,20
drv 275,10,10
drv 285,10,20 
drh 45,20,10
drh 65,20,30
drh 115,20,30
drh 195,20,30
drh 235,20,10
drh 255,20,20
drv 55,20,10
drv 85,20,10
drv 105,10,20
drv 155,10,30
drv 195,30,20
drv 215,20,50
drv 235,20,10
drh 55,30,30
drh 95,30,60
drh 165,30,10
drh 185,30,20
drh 225,30,60
drv 75,30,30
drv 95,30,10
drv 85,40,10
drv 125,40,60
drv 125,110,40
drv 135,50,40
drv 135,120,20
drv 145,70,20
drv 145,100,20
;drh 110,120,10
drv 155,60,10
drv 155,100,10
drv 155,120,20
drv 145,140,10
drh 135,130,20
drh 45,50,10
drh 85,50,10
drh 105,50,10
drh 135,50,40
drv 45,50,10
drv 95,50,10
drh 95,60,10
drv 115,50,20
drh 145,60,10
drv 165,60,20
drh 165,70,10
drh 45,60,40
drv 55,60,10
drv 55,90,10
drv 85,60,10
drh 85,70,30
drv 95,70,10
drv 65,70,20
drh 65,70,10
drv 75,70,30
drv 85,80,10
drh 85,90,20
drv 105,80,10
drh 55,100,60
drv 115,90,10
drh 115,90,10
drh 55,110,50
drh 115,110,20
drv 105,110,10 
drh 175,40,10
drh 175,60,10 
drv 185,60,10
drh 185,70,10
drv 195,70,20
drv 235,40,10 ;1
drv 235,70,30
drv 235,130,10
drv 245,30,10
drv 245,50,40
drv 245,100,10
drv 245,120,30
drv 255,40,10
drv 255,60,20
drv 255,90,10
drv 255,110,10
drv 265,30,30
drv 265,80,10
drv 265,120,20
drv 275,50,40
drv 275,110,10
drv 275,130,10
drv 285,40,10
drv 285,60,50
drv 285,130,20
drh 285,50,10
drh 275,120,20
drh 255,140,20
drh 245,130,10
drh 225,140,10 
drh 235,120,10
drh 225,110,50
drh 255,100,30
;drh 235,60,20
drh 265,40,20
drh 235,50,20
drv 165,130,20
drh 165,140,20
drv 195,130,10
drh 195,140,10
drv 215,130,20
drh 205,130,10
drv 205,120,10
drh 195,120,20
drv 195,110,10
drh 185,100,40
drh 205,110,10
drv 205,90,20
drh 155,80,30
drv 185,80,40
drv 175,90,20
drh 165,100,10
drv 165,90,10
drh 135,90,30
drh 175,130,20
drh 255,120,10
drh 275,60,10
drh 265,70,10
drh 255,60,10
drh 255,80,10
drh 235,90,20
drv 225,90,50
drh 205,40,30
drh 205,70,20
drv 225,50,20
drh 225,60,10
drv 205,50,10
drh 185,50,20
drh 195,60,10
drh 125,100,30
drh 85,40,40
drh 135,40,30
drh 135,120,10
drh 165,120,20
drv 175,120,10
drh 155,110,10
drv 165,110,10
drh 195,80,40
drv 215,80,10
drv 115,70,10
drh 105,80,10 

endm drawmaze
;--------------------------
gotflag1p macro pwin,pclr,px,py


	mov al , 1
	mov pwin,al	
	drawflag flag1X,flag1Y,delete
	
	drawplayer player1X,player1Y,winclr
	delaying
	drawplayer player1X,player1Y,pclr
	delaying
	drawplayer player1X,player1Y,winclr
	delaying
	drawplayer player1X,player1Y,pclr
	
endm gotflag1p
;-------------------------------------------
gotflag2p macro pwin,pclr,px,py


	mov al , 1
	mov pwin,al	
	drawflag flag1X,flag1Y,delete
	
	drawplayer player2X,player2Y,winclr
	delaying
	drawplayer player2X,player2Y,pclr
	delaying
	drawplayer player2X,player2Y,winclr
	delaying
	drawplayer player2X,player2Y,pclr
	
endm gotflag2p
