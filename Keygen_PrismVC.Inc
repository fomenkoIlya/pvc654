include conengine.inc
includelib conengine.lib

SOUND_ID = 2

Main               proto
GenerateKey        proto :dword ;[0-2]variant key
GenerateLettersPart proto :dword,:dword
InitApp            proto
CheckButtonClick   proto
CreateCheckBtnDown proto
CreateCopyBtnDown  proto
Scroller           proto :dword,:dword,:dword,:dword,:dword
FillArray          proto

.const
MIN_SN equ 4298881
MAX_SN equ 7FFFFFFFh

.data
sn           dd 100 dup(0)
buffer       db 16 dup(0)
szSerial     db 32 dup(0)
closeConsole dd 0
dCopy        dd 0
id_timer     dd 0
szAbout db "              Keygen for Prism Video Converter v6.54 Tehno Syndrom 2020         ",0
sx           dd 80
index        dd 0
sel          dd 0

;-----------------------
szAlpha db "abcdef",0
szStr1  db "mnbvaq",0
szStr2  db "cxzlbr",0
szStr3  db "kjhgct",0
szStr4  db "fdsady",0
szStr5  db "poiueu",0
szStr6  db "ytrefo",0
szStr7  db "wqalgx",0
szStr8  db "ksjdhv",0
szStr9  db "hfgbif",0
szStr10 db "qazwja",0
szStr11 db "sxedkf",0
szStr12 db "crfvlg",0
szStr13 db "tgbymh",0
szStr14 db "hnujni",0
szStr15 db "miklop",0
szStr16 db "plokpc",0
;-----------------------
table dd offset szStr10
      dd offset szStr11
      dd offset szStr12
      dd offset szStr13
      dd offset szStr14
      dd offset szStr15
      dd offset szStr16
      dd offset szStr1
      dd offset szStr2
      dd offset szStr3
      dd offset szStr4
      dd offset szStr5
      dd offset szStr6
      dd offset szStr7
      dd offset szStr8
      dd offset szStr9
     
pChar     dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h                 
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h   
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h 
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,5Bh,3Ch,78h,3Ch   
          dw  5Dh,3Ch,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2554h,30h,2550h,30h,2550h,30h   
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h 
          dw  2550h,30h,2550h,30h,2550h,30h,4bh,30h    
          dw  65h,30h,79h,30h,67h,30h,65h,30h           
          dw  6eh,30h,20h,30h,50h,30h,72h,30h         ;Pr
          dw  69h,30h,73h,30h,6dh,30h,20h,30h         ;ism 
          dw  56h,30h,69h,30h,64h,30h,65h,30h         ;Vide 
          dw  6fh,30h,20h,30h,43h,30h,6fh,30h         ;o Co
          dw  6eh,30h,76h,30h,65h,30h,72h,30h         ;nver
          dw  74h,30h,65h,30h,72h,30h,20h,30h         ;ter 
          dw  76h,30h,36h,30h,2eh,30h,35h,30h         ;v6.5
          dw  34h,30h,2550h,30h,2550h,30h,2550h,30h   ;4
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,2557h,30h,20h,30h     
          dw  20h,30h,20h,07h,20h,07h,20h,07h           
          dw  20h,07h,20h,07h,20h,07h,20h,07h         
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h            
          dw  20h,30h,2551h,30h,20h,30h,20h,30h           
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h   
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h   
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h           
          dw  20h,30h,20h,07h,20h,07h,20h,07h              
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h    
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h           
          dw  20h,30h,2551h,30h,20h,30h,20h,30h             
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h    
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h    
          ;---------------------------------
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,2eh,20h,2eh,2554h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2557h,2eh
          dw  20h,2eh,20h,2eh,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,2eh,20h,2eh,2551h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,50h,2eh,72h,2eh   ;Press check button
          dw  65h,2eh,73h,2eh,73h,2eh,20h,2eh
          dw  63h,2eh,68h,2eh,65h,2eh,63h,2eh
          dw  6bh,2eh,20h,2eh,62h,2eh,75h,2eh
          dw  74h,2eh,74h,2eh,6fh,2eh,6eh,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,2551h,2eh
          dw  20h,2eh,20h,2eh,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,2eh,20h,2eh,255ah,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,2550h,2eh
          dw  2550h,2eh,2550h,2eh,2550h,2eh,255dh,2eh
          dw  20h,2eh,20h,2eh,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,2eh,20h,2eh
          dw  20h,2eh,20h,2eh,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,2551h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,2551h,30h,20h,30h         
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,255Ah,30h,2550h,30h,2550h,30h      
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,2550h,30h,2Ah,30h      
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,2550h,30h,2550h,30h
          dw  2550h,30h,2550h,30h,255Dh,30h,20h,30h     
          dw  20h,30h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,30h,20h,30h,20h,30h
          dw  20h,30h,20h,07h,20h,07h,20h,07h               
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,0h         
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h          
      ;----------------------------------------
bGen      dw  20h,07h,20h,37h,63h,37h,68h,37h  ;Button Generate
          dw  65h,37h,63h,37h,6bh,37h,20h,37h      
          dw  20h,07h,20h,70h,20h,70h,20h,70h  
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h  
          dw  20h,70h,20h,70h,20h,70h,20h,70h 
          dw  20h,70h,20h,70h,20h,70h,20h,70h  
          dw  20h,70h,20h,70h,20h,70h,20h,70h        
          dw  20h,70h,20h,70h,20h,70h,20h,70h   
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          ;--------------------------------------
bCopy     dw  20h,07h,20h,37h,63h,37h,6fh,37h  ;Button Copy 
          dw  70h,37h,79h,37h,20h,37h,20h,37h
          dw  20h,07h,20h,70h,20h,70h,20h,70h   
          dw  20h,70h,20h,70h,20h,70h,20h,70h
          dw  20h,70h,20h,70h,20h,70h,20h,70h 
          dw  20h,70h,20h,70h,20h,70h,20h,70h         
          ;-----------------------------------          
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h   
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
          dw  20h,07h,20h,07h,20h,07h,20h,07h
                
bGenDown  dw  20h,2eh,63h,2eh,68h,2eh  
          dw  65h,2eh,63h,2eh,6bh,2eh
          dw  20h,2eh
          ;-----------------------------------
bCopyDown dw  20h,2eh,63h,2eh,6fh,2eh  
          dw  70h,2eh,79h,2eh,20h,2eh
          dw  20h,2eh
;---------------------------------------------    
    