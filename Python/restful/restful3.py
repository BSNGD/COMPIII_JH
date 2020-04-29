import requests
import time

def RequestTime():
    #using worldtimeapi.org
    resp = requests.get('http://worldtimeapi.org/api/ip')
    if resp.status_code != 200:
        raise ApiError('GET /tasks/ {}'.format(resp.status_code))
    return(time.strftime("%I:%M%p", time.localtime(int(resp.json()['unixtime']))))

if __name__ == "__main__":
    RequestTime()