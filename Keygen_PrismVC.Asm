include Keygen_PrismVC.Inc

.data
keyValue dd 0

.code
start:  
    fn InitApp
    fn Main
    ;----------------------
    exit

Main proc
    .while closeConsole == 0
        fn MouseLeft_pressed
        mov ebx,eax
        cwde      ;x
        shr ebx,16;y
        ;btn close
        cmp ebx,4
        jne @@L0
        cmp eax,67
        jne @@L0
        inc dword ptr[closeConsole]
        jmp @@Done
@@L0:        
        cmp ebx,26
        jne @@Done
        cmp eax,16
        jle @@L1
        cmp eax,24
        jge @@L1
        ;button Check pressed-------
        fn CreateCheckBtnDown
        fn CheckButtonClick
        ;---------------------------
        mov dword ptr[dCopy],1
        jmp @@Done
@@L1:
        cmp eax,56
        jle @@Done
        cmp eax,64
        jge @@Done
        ;button Copy pressed--------
        cmp dword ptr[dCopy],0
        je @@Done
        fn CreateCopyBtnDown
        fn CopyToClipboard,offset szSerial
        ;---------------------------
        mov dword ptr[dCopy],0
@@Done:        
    .endw
    fn timeKillEvent,id_timer
@@Ret:    
    ret
Mainz endp

InitApp proc uses ebx esi edi
    LOCAL cr:COORD
    LOCAL srect:SMALL_RECT
    LOCAL hOut:dword
    
    fn GetStdHandle,-11
    mov dword ptr[hOut],eax
    fn SetConsoleTitle,"Prism Video Converter 6.54 Keygen"
    fn SetConsoleWindowSize,80,30,0
    fn SetConsoleCenterScreen,0
    fn HideConsoleCursor   
    fn PlayXmSound,SOUND_ID 
       
@@:    
    mov srect.Left,0
    mov srect.Top,0
    mov srect.Right,80
    mov srect.Bottom,30  
    mov cr.x,80
    mov cr.y,30
    
    fn crt_srand,rv(crt_time,0)
    fn FillArray
    
    mov ebx,cr
    lea edx,srect    
    fn WriteConsoleOutputW,hOut,offset pChar,ebx,0,edx
    fn timeSetEvent,210,0,offset Scroller,0,1
    mov dword ptr[id_timer],eax
    
    ret
InitApp endp

FillArray proc uses ebx esi edi 
    lea esi,sn
    xor ebx,ebx
    mov edi,MIN_SN
    jmp @@For
@@In:
    fn RangedRand,1,100
    dec eax
    add eax,edi
    mov dword ptr[esi+ebx*4],eax
    inc ebx
@@For:
    cmp ebx,100
    jl @@In
            
    ret
FillArray endp

Scroller proc uses ebx esi edi idTimer:dword,uMsg:dword,dwUser:dword,Res1:dword,Res2:dword
    LOCAL buf[84]:byte
      
@@Scroll:
    cmp dword ptr[sx],0
    ja @@Dec
    inc dword ptr[sel]
    cmp dword ptr[sel],80
    jle @@Next
    mov dword ptr[sx],80
    mov dword ptr[sel],0
    mov dword ptr[index],0
    jmp @@Scroll
@@Dec:
    dec dword ptr[sx] 
@@Next:  
    cmp dword ptr[index],80
    je @@L0
    inc dword ptr[index]
@@L0:
    fn Gotoxy,sx,0
    fn SetConsoleColor,7,LightRed
    lea esi,szAbout
    add esi,sel
    lea edi,buf
    xor ebx,ebx  
@@L1:
    mov al,byte ptr[esi+ebx]
    mov byte ptr[edi+ebx],al
    cmp al,0
    je @@Print
    inc ebx
    cmp ebx,dword ptr[index]
    jl @@L1
    mov byte ptr[edi+ebx],0   
@@Print:    
    fn crt_printf,edi
    
    ret
Scroller endp

CreateCheckBtnDown proc uses ebx esi edi
    LOCAL cr:COORD
    LOCAL srect:SMALL_RECT
    LOCAL hOut:dword
    
    fn GetStdHandle,-11
    mov dword ptr[hOut],eax
    mov cr.x,7
    mov cr.y,1
    mov srect.Left,17
    mov srect.Top,26
    mov srect.Right,24
    mov srect.Bottom,27  
    mov ebx,dword ptr[cr]
    fn WriteConsoleOutputW,hOut,offset bGenDown,ebx,0,addr srect
    fn Sleep,250
    lea esi,bGen
    add esi,4
    fn WriteConsoleOutputW,hOut,esi,ebx,0,addr srect
    
    ret
CreateCheckBtnDown endp

CreateCopyBtnDown proc uses ebx esi edi
    LOCAL cr:COORD
    LOCAL srect:SMALL_RECT
    LOCAL hOut:dword
    
    fn GetStdHandle,-11
    mov dword ptr[hOut],eax
    mov cr.x,7
    mov cr.y,1
    mov srect.Left,57
    mov srect.Top,26
    mov srect.Right,64
    mov srect.Bottom,27   
    mov ebx,dword ptr[cr]
    fn WriteConsoleOutputW,hOut,offset bCopyDown,ebx,0,addr srect
    fn Sleep,250
    lea esi,bCopy
    add esi,4
    fn WriteConsoleOutputW,hOut,esi,ebx,0,addr srect
    
    ret
CreateCopyBtnDown endp

CheckButtonClick proc uses ebx edx esi edi
    LOCAL num:dword
    
    fn szCopy,offset szAlpha,offset buffer
    fn RangedRand,1,100
    ;get random legal number
    mov dword ptr[num],MIN_SN
    add dword ptr[num],eax
    mov esi,dword ptr[num]
    
    ;calculate edx value   
    mov eax,38E38E39h
    mul esi
    mov edi,edx
    shr edi,1
    lea eax,dword ptr[edi+edi*8]
    mov edx,esi
    sub edx,eax
     
    fn GenerateKey,0    
    ;----------------------
    mov byte ptr[buffer+6],'t'
    mov byte ptr[buffer+7],'s'
    mov byte ptr[buffer+8],0
    ;-----------------------
    lea esi,buffer
    fn Gotoxy,24,13
    fn SetConsoleColor,cGreen,cYellow
    printf("                              ")
    mov eax,dword ptr[num]
    fn wsprintf,offset szSerial,"%d-",eax
    fn szCatStr,offset szSerial,esi
    lea esi,szSerial
    fn szLen,esi
    mov ebx,80
    sub ebx,eax
    shr ebx,1
    fn Gotoxy,ebx,13
    printf(esi)
      
    ret
CheckButtonClick endp

GenerateKey proc uses ebx edx esi edi variantKey:dword
    
    ;1---------------------------
    lea eax,dword ptr[table]
    lea eax,dword ptr[eax+7*4] ;ptr table in half array
    
    imul ebx,edx,4
    add eax,ebx
    fn GenerateLettersPart,eax,offset buffer
    ;2---------------------------
    mov eax,edi
    xor edx,edx
    mov edi,7
    div edi
    ;---------
    lea eax,dword ptr[table]
    imul ebx,edx,4
    add eax,ebx  
    fn GenerateLettersPart,eax,offset buffer
    ;3---------------------------
    mov eax,4104105h
    mul esi
    sub esi,edx
    shr esi,1
    add esi,edx
    shr esi,5
    mov eax,38E38E39h
    mul esi
    mov edi,edx
    shr edi,1
    lea eax,dword ptr[edi+edi*8]
    mov edx,esi
    sub edx,eax
    ;------
    lea eax,dword ptr[table]
    lea eax,dword ptr[eax+7*4]
    imul ebx,edx,4
    add eax,ebx    
    fn GenerateLettersPart,eax,offset buffer
    ;4---------------------------
    mov eax,edi
    xor edx,edx
    mov edi,7
    div edi
    ;----
    lea eax,dword ptr[table]
    imul ebx,edx,4
    add eax,ebx  
    fn GenerateLettersPart,eax,offset buffer
    ;5---------------------------
    mov eax,4104105h
    mul esi
    sub esi,edx
    shr esi,1
    add esi,edx
    shr esi,5
    mov eax,38E38E39h
    mul esi
    mov edi,edx
    shr edi,1
    lea eax,dword ptr[edi+edi*8]
    mov edx,esi
    sub edx,eax
    ;--------
    lea eax,dword ptr[table]
    lea eax,dword ptr[eax+7*4]
    imul ebx,edx,4
    add eax,ebx    
    fn GenerateLettersPart,eax,offset buffer
    ;6---------------------------
    mov eax,edi
    xor edx,edx
    mov edi,7
    div edi
    ;------
    lea eax,dword ptr[table]
    imul ebx,edx,4
    add eax,ebx  
    fn GenerateLettersPart,eax,offset buffer
    ;7---------------------------
    mov eax,4104105h
    mul esi
    sub esi,edx
    shr esi,1
    add esi,edx
    shr esi,5
    mov eax,38E38E39h
    mul esi
    mov edi,edx
    shr edi,1 
    lea eax,dword ptr[edi+edi*8]
    sub esi,eax
    ;------
    lea eax,dword ptr[table]
    lea eax,dword ptr[eax+7*4]
    imul ebx,esi,4
    add eax,ebx    
    fn GenerateLettersPart,eax,offset buffer
    ;8---------------------------
    xor edx,edx
    mov eax,edi
    mov esi,7
    div esi
    ;---------
    lea eax,dword ptr[table]
    imul ebx,edx,4
    add eax,ebx  
    fn GenerateLettersPart,eax,offset buffer
    ;9---------------------------
    lea eax,dword ptr[table]
    mov edx,7
    imul ebx,edx,4
    add eax,ebx
    fn GenerateLettersPart,eax,offset buffer
    ;10---------------------------
    lea eax,dword ptr[table]
    mov edx,3
    imul ebx,edx,4
    add eax,ebx
    fn GenerateLettersPart,eax,offset buffer
    ;11---------------------------
    mov eax,variantKey ;[0-2]
    cdq
    mov esi,9
    idiv esi
    mov esi,eax
    ;---------
    lea eax,dword ptr[table]
    lea eax,dword ptr[eax+7*4]
    imul ebx,edx,4
    add eax,ebx  
    fn GenerateLettersPart,eax,offset buffer
    ;12---------------------------
    mov eax,esi
    cdq
    mov esi,7
    idiv esi
    ;-----
    lea eax,dword ptr[table]
    imul ebx,edx,4
    add eax,ebx  
    fn GenerateLettersPart,eax,offset buffer
     
    ret
GenerateKey endp

GenerateLettersPart proc uses ebx ecx esi edi lpStr:dword,lpResultBuffer:dword
    mov esi,lpStr
    mov esi,[esi]
    mov ecx,lpResultBuffer
    ;1 letter ---------------------
    movzx edx,byte ptr[esi] ;1 letter from str
    movzx eax,byte ptr[ecx] ;1 letter from "abcdef" start string
    lea eax,dword ptr[eax+edx-0C2h]
    cdq
    mov edi,1Ah
    idiv edi
    add edx,61h
    mov byte ptr[ecx],dl ;rewrite "abcdef" in buffer!
    ;2 letter ---------------------
    movzx eax,byte ptr[esi+1]
    movzx edx,byte ptr[ecx+1]
    lea eax,dword ptr[eax+edx-0C2h]
    cdq
    idiv edi
    add edx,61h
    mov byte ptr[ecx+1],dl
    ;3 letter ---------------------
    movzx eax,byte ptr[esi+2]
    movzx edx,byte ptr[ecx+2]
    lea eax,dword ptr[eax+edx-0C2h]
    cdq
    idiv edi
    add edx,61h
    mov byte ptr[ecx+2],dl
    ;4 letter ---------------------
    movzx eax,byte ptr[esi+3]
    movzx edx,byte ptr[ecx+3]
    lea eax,dword ptr[eax+edx-0C2h]
    cdq
    idiv edi
    add edx,61h
    mov byte ptr[ecx+3],dl
    ;5 letter ---------------------
    movzx eax,byte ptr[esi+4]
    movzx edx,byte ptr[ecx+4]
    lea eax,dword ptr[eax+edx-0C2h]
    cdq
    idiv edi
    add edx,61h
    mov byte ptr[ecx+4],dl
    ;6 letter ---------------------
    movzx eax,byte ptr[esi+5]
    movzx edx,byte ptr[ecx+5]
    lea eax,dword ptr[eax+edx-0C2h]
    mov esi,edi
    cdq
    idiv esi
    add edx,61h
    mov byte ptr[ecx+5],dl
   
    ret
GenerateLettersPart endp

end start