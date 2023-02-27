str_length = int(input())
str = input()
set_length = int(input())
element_set = []
count  = 0
for count in range(0, set_length):
    element_set.append(int(input()))

element_set = set(element_set)

count = 0

for i in range(0, str_length):
    for j in range(2, str_length):
        substr = str[i:j]
        revstr = reversed(substr)
        if(substr == revstr):
            if (len(substr) in element_set):
                count += 1
                print(substr)

print(count)