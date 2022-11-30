import hashlib

block = 1
newHash = '0000000000000000000000000000000000000000000000000000000000000000'

goOn = 1

while goOn == 1:
  
  try: #要進行錯誤捕捉的程式碼
    data = input()
    
  except EOFError: #如果讀到EOF，就會執行這裡
    print(newHash)
    goOn = 0
  
  else: #如果沒有EOF，就會執行這裡
    NONCE = 0
    previousHash = newHash
      
    found = 0
    while found == 0:
      z = str(block)+str(NONCE)+data+previousHash
      newHash = hashlib.sha256 (z.encode()).hexdigest()
        
      if newHash [:3] == '000':
        found = 1
          
      NONCE += 1

    block += 1
