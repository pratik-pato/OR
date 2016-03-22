#! /usr/bin/python

import sys

n = int(raw_input())
eq = []

cj = raw_input()
cj = cj.split("\n")[0]
cj = cj.split(" ")
for i in range(0, len(cj)):
    cj[i] = int(cj[i])

print cj

for i in range(0, n):
    eq.append(raw_input())
    eq[i] = eq[i].split("\n")[0]
    eq[i] = eq[i].split(" ")
    for j in range(0, len(eq[i])):
        eq[i][j] = int(eq[i][j])
    print eq[i]

coeff = []

for i in range(0, n):
    coeff.append(0)

zj = 0

for i in range(0, n):
    zj += (eq[i][-1:][0] * coeff[i])

print zj

maximum = 0
enter = -1

for i in range(0, (len(eq[0])-1)):
    cj_zj = 0

    for j in range(0, n):
        cj_zj += coeff[j] * eq[j][i]

    cj_zj = cj[i] - cj_zj

    print cj_zj, maximum

    if cj_zj > maximum:
        maximum = cj_zj
        enter = i

print enter
if enter >= 0:
    print "%dth variable enters"%enter

maximum = 0

for i in range(0, n):
    ratio = eq[i][-1:][0]/eq[i][enter]
    print ratio
    if ratio > 0:
        if ratio > maximum:
            maximum = ratio
            leave = i

print maximum, leave

coeff[leave] = cj[enter]

print coeff
