import hashlib

money = 0

a = input()

block = 1
NONCE = 0
previousHash = '0000000000000000000000000000000000000000000000000000000000000000' 

found = 0
while found == 0:
  z = str(block)+str(NONCE)+a+previousHash
  newHash = hashlib.sha256 (z.encode()).hexdigest()
        
  if newHash[:4] == '0000':
    found = 1
          
  NONCE += 1

b = input()
NONCE = input()

if b[:4] == 'Eric':
  block = 2
  previousHash = newHash
  dollar = 0
     
  found = 0
  while found == 0:
    b = 'Eric pays Alice %s dollars' %(str(dollar))
    
    z = str(block)+str(NONCE)+b+previousHash
    newHash = hashlib.sha256 (z.encode()).hexdigest()
    
    if newHash[:4] == '0000':
      money += dollar

      found = 1
            
    dollar += 1

else:
  block = 2
  previousHash = newHash
  dollar = 0
     
  found = 0
  while found == 0:
    b = 'Alice pays Eric %s dollars' %(str(dollar))
    
    z = str(block)+str(NONCE)+b+previousHash
    newHash = hashlib.sha256 (z.encode()).hexdigest()
    
    if newHash[:4] == '0000':
      money -= dollar
      
      found = 1

    dollar += 1

c = input()

block = 3
NONCE = 0
previousHash = newHash

found = 0
while found == 0:
  z = str(block)+str(NONCE)+c+previousHash
  newHash = hashlib.sha256(z.encode()).hexdigest()
        
  if newHash[:4] == '0000':
    found = 1
          
  NONCE += 1


if c[:4] == 'Paul':
  s = c.split()

  money += int(s[3])
else:
  s = c.split()

  money -= int(s[3])

string = a.split("&")
for i in range(len(string)):
  if string[i][:16] == 'David pays Alice':
    s = string[i].split()

    money += int(s[3])

d = input()

dollar -= 1
NONCE -= 1
print(str(dollar) + "," + str(money) + "," + str(NONCE))
