import endpoint
import time

endtime = endpoint.RequestTime("utc")
endtime = endpoint.RequestTime("est")
print (endtime['currentDateTime'])