import hashlib

block = 1
newHash = '0000000000000000000000000000000000000000000000000000000000000000'

goOn = 1

while goOn == 1:
  
  try:
    data = input()
    
  except EOFError:
    print(newHash)
    goOn = 0
  
  finally:
  
    #print(data)
      
    NONCE = 0
    previousHash = newHash
      
    found = 0
    while found == 0:
        
      z = str(block)+str(NONCE)+data+previousHash
      newHash = hashlib.sha256 (z.encode()).hexdigest()
        
      if newHash [:3] == '000':
        found = 1
          
      NONCE += 1
        
    #print(newHash)
    #print(NONCE)

    block += 1

