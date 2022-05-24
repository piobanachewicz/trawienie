import random

cuts = int(input("Wpisz liczbe ciec: "))
size = ((cuts+1) * (cuts+2)) / 2
map = []

length = 0

for i in range(cuts+1):
    map.append(random.randint(1, 15))
    length += map[i]

set = []

for i in range(len(map)):
    tmp = 0
    for j in range(i, 0, -1):
        tmp += map[j]
        set.append(tmp)
    set.append(length - tmp)


map.append(map[0])
map.pop(0)
map.reverse()

print("Mapa:")
print(map)

set.sort()
print("Instancja:")
for i in set:
    print(i, end=" ")

if size == len(set):
    print("\nOK")
else:
    print("\nNie OK")

input("Nacisnij enter aby wyjsc")
