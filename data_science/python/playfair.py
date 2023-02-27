def EncryptData(data, key):
    encrypted_data = ""
    playfair = []

    for i in key:
        playfair.append(i)

    alphabets = []

    for i in range(65,91,1):
        c = chr(i).lower()
        if(c == 'j'):
            continue
        if(c not in playfair):
            playfair.append(c)

    if (playfair.__len__() > 25 ):
        print("Matrix length exceeded. Length: ", playfair.__len__())
        exit(0)
    print(playfair)

    return encrypted_data

data = "".join(dict.fromkeys(input("Enter the Data: ").lower().replace('j', 'i',-1)))
key = "".join(dict.fromkeys(input("Enter the key: ").lower().replace('j', 'i', -1)))
print(data, key)
encrypted_data = EncryptData(data, key)