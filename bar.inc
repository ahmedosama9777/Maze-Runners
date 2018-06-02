drawline Macro 
local loop1
	
		mov cx , 0
		mov dx , 152
		mov bx,0
		
		loop1:
		
     
			mov al,0Fh       ;Pixel color 
			mov ah,0ch       ;Draw Pixel Command back:   
			int 10h
			inc cx
			inc bx 
			cmp bx,319
		
		jnz loop1
ENDM drawline

