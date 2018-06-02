delaying MACRO
local loop1

;start delay
mov bp, 5
mov si, 5
loop1:
dec bp
nop
jnz loop1
dec si
cmp si,0    
jnz loop1
; end delay

endm delaying
;-----------------------------------
shootup macro startx,starty,kill
local draw 
local delete
local delete1
local done
local delete2
local delete3


mov cx,startx ;Column
mov dx,starty ;Row 
inc cx
dec dx
mov bx,0

draw:
mov al,0fh   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
inc bx 
int 10h
dec dx 
mov ah,0DH
int 10h

cmp al,mclr
je delete 
cmp al,Fclr
je delete 
cmp al,cpClr
je delete 
cmp al,flag1clr
je delete


cmp al,clr2
je delete2 
cmp al,clr1
je delete2

jmp draw
delete:
mov kill,0
delaying
mov cx,startx ;Column
mov dx,starty ;Row 
inc cx
dec dx
mov al,00h   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
delete1: int 10h
dec dx
dec bx
cmp bx,0
je done
jmp delete1
delete2: 
mov kill,10
delaying
mov cx,startx ;Column
mov dx,starty ;Row 
inc cx
dec dx
mov al,00h   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
delete3: int 10h
dec dx
dec bx
cmp bx,0
je done
jmp delete3
done:
mov bl,kill
endm shootup
    
;------------------------------------------------------
shootdown macro startx,starty,kill
local draw1
local delete4
local delete5
local done1
local delete6
local delete7

mov cx,startx ;Column
mov dx,starty ;Row 
add dx,8
inc cx
mov bx,0
draw1:
mov al,0fh   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
inc bx 
int 10h
inc dx 
mov ah,0DH
int 10h

cmp al,mclr
je delete4 
cmp al,cpClr
je delete4 
cmp al,Fclr
je delete4 

cmp al,flag1clr
je delete4

cmp al,clr2
je delete6 
cmp al,clr1
je delete6
jmp draw1
delete4:
mov kill,0
delaying

mov cx,startx ;Column
mov dx,starty ;Row 
add dx,8
inc cx
mov al,00h   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
delete5: int 10h
inc dx
dec bx
cmp bx,0
je done1
jmp delete5
delete6: 
delaying
mov kill,10
mov cx,startx ;Column
mov dx,starty ;Row 
add dx,8
inc cx
mov al,00h   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
delete7: int 10h
inc dx
dec bx
cmp bx,0
je done1
jmp delete7
done1:
mov bl,kill
endm shootdown
;------------------------------------------------------
shootleft macro startx,starty,kill
local drawl 
local deletel
local deletel1
local donel
local deletel2
local deletel3

mov cx,startx ;Column
mov dx,starty ;Row 
dec cx
add dx,4
mov bx,0
drawl:
mov al,0fh   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
inc bx 
int 10h
dec cx 
mov ah,0DH
int 10h

cmp al,mclr
je deletel 
cmp al,cpClr
je deletel 
cmp al,Fclr
je deletel 

cmp al,flag1clr
je deletel

cmp al,clr2
je deletel2 
cmp al,clr1
je deletel2
jmp drawl
deletel:
mov kill,0
;start delay
mov bp, 5
mov si, 5
delaying
mov cx,startx ;Column
mov dx,starty ;Row 
dec cx
add dx,4
mov al,00h   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
deletel1: int 10h
dec cx
dec bx
cmp bx,0
je donel
jmp deletel1
deletel2: 
mov kill,10
delaying
mov cx,startx ;Column
mov dx,starty ;Row 
dec cx
add dx,4
mov al,00h   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
deletel3: int 10h
dec cx
dec bx
cmp bx,0
je donel
jmp deletel3
donel:
mov bl,kill
endm shootleft
;------------------------------------------------------
shootright macro startx,starty,kill
local drawr 
local deleter
local deleter1
local doner
local deleter2
local deleter3


mov cx,startx ;Column
mov dx,starty ;Row 
add cx,4
add dx,4
mov bx,0
drawr:
mov al,0fh   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
inc bx 
int 10h
inc cx 
mov ah,0DH
int 10h


cmp al,mclr
je deleter 

cmp al,Fclr
je deleter

cmp al,cpClr
je deleter

cmp al,flag1clr
je deleter

cmp al,clr1
je deleter2 
cmp al,clr2
je deleter2
jmp drawr
deleter:
mov kill,0
;start delay
mov bp, 5
mov si, 5
delaying
mov cx,startx ;Column
mov dx,starty ;Row 
add cx,4
add dx,4
mov al,00h   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
deleter1: int 10h
inc cx
dec bx
cmp bx,0
je doner
jmp deleter1
deleter2: 
mov kill,10
delaying
mov cx,startx ;Column
mov dx,starty ;Row 
add cx,4
add dx,4
mov al,00h   ;Pixel color
mov ah,0ch  ;Draw Pixel Command
deleter3: int 10h
inc cx
dec bx
cmp bx,0
je doner
jmp deleter3
doner:
mov bl,kill
endm shootright
;------------------------------------------------------