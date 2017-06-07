#
# Makefile for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm
#
# Made by MARZI Nicolas
# Login   <marzi_n@etna-alternance.net>
#
# Started on  Mon Jun  5 13:26:04 2017 MARZI Nicolas
# Last update Mon Jun  5 13:27:36 2017 MARZI Nicolas
#

.name zoidberg
    .comment Whoop Whoop Whoop

#test: add r1,r2,r3
sti r1,%:live,%1
and r1,%0,r1
live: live %1
zjmp %:live