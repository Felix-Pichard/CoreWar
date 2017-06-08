# CoreWar

## Instructions:
    - live
Suivie de 4 octets qui représente le numéro du joueur. Cette
instruction indique que ce joueur est en vie. (pas d’octet de
codage des paramètres).

    - ld
Cette instruction prend 2 paramètres le deuxième est forcement
un registre (pas le PC). Elle load la valeur du premier paramètre
dans le registre. Cette opération modifie le carry. ld 34,r3 charge
les REG_SIZE octets a partir de l’adresse (PC + (34 %
IDX_MOD)) dans le registre r3.

    - st
Cette instruction prend 2 paramètres. Elle store (REG_SIZE
OCTET)la valeur du premier argument (toujours un registre)
dans le second. st r4,34 store la valeur de r4 a l’adresse ( PC +
(34 % IDX_MOD)) st r3,r8 copie r3 dans r8

    - add
Cette instruction prend 3 registres en paramètre, additionne le
contenu des 2 premiers et met le résultat dans le troisième. Cette
opération modifie le carry. add r2,r3,r5 additionne r2 et r3 et mets
le résultat dans r5

    - sub
même que add mais soustrait

    - and
p1 & p2 -> p3 le paramètre 3 et toujours un registre. Cette
opération modifie le carry. and r2, %0,r3 met r2 & 0 dans r3

    - or
même que and mais avec le ou ( | du c).

    - xor
même que and mais avec le ou exclusif (du c). 

    - zjmp
Cette instruction n’est pas suivie d’octet pour décrire les
paramètres. Elle prend toujours un index (IND_SIZE) et fait un
saut a cet index si le carry est a un. Si le carry est nul, zjmp ne
fait rien mais consomme le même temps. zjmp %23 met si carry
== 1 met (PC + (23 % IDX_MOD)) dans le PC.

    - ldi
Cette opération modifie le carry. ldi 3,%4,r1 lit IND_SIZE octets
a l’adresse : (PC + (3 % IDX_MOD)) ajoute 4 a cette valeur. On
nommera S cette somme. On lit REG_SIZE octet a l’adresse (PC
+ (S % IDX_MOD)) qu’on copie dans r1. Les paramètre 1 et 2
sont des index.

    - sti
sti r2,%4,%5 sti copie REG_SIZE octet de r2 a l’adresse (4 + 5)
Les paramètres 2 et 3 sont des index. Si les paramètres 2 ou 3 sont
des registres, on utilisera leur contenu comme un index


## Values:
r1      => Value of register
%:name  => Address of function
%1      => Static value


## Struct Instruction

opcode => unsigned char
nbr_args => unsigned char
args_type_t => type[MAX_ARGS_NUMBER]
args => int