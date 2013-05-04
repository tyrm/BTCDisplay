import requests
import json
import time
import serial

XBee = serial.Serial('/dev/ttyUSB0', 9600)

loop = True
lastPrice = 0

def getString():
  global lastPrice

  data = requests.get('http://data.mtgox.com/api/2/BTCUSD/money/ticker')

  goxData = data.json()

  newPrice = int(goxData['data']['sell']['value_int'])
  price =  str(goxData['data']['sell']['value_int'])

  retStr = str(price[:-3])

  if newPrice > lastPrice:
    retStr = retStr+'u'
  elif newPrice < lastPrice:
    retStr = retStr+'d'
  else:
    retStr = retStr+'n'

  lastPrice = int(goxData['data']['sell']['value_int'])

  return retStr

while loop:
  finalString =  getString()+'\n'

  XBee.write(finalString)
  
  time.sleep(5)
  #loop = False


