import turtle
import serial
import time

#터틀 초기 설정
s = turtle.getscreen()
#거북이 변수에 지정, 거북이 초기 설정
t = turtle.Turtle()
t.color("blue")
t.shape("turtle")
t.shapesize(1.5,1.5,1.5)


#시리얼로 아두이노에서 신호 받기
#연결 확인
connection = None
#current_signal

def connect_signal(port='COM8'):
    global connection
    try:
        conn = serial.Serial(port, 9600, timeout=0.05)
        time.sleep(0.1)
        print("연결 성공")
        return conn
    except:
        print("연결 실패")
        return False

    

#신호 동작 함수
def main():
    connection = connect_signal()
    if not connection:
        return
    while True:
        try:
            data = connection.readline().decode().strip()
            #신호를 받은 후에 터틀 움직임
            if data: 
                print("받은 신호:", data)
                
                if data =="forward!":
                    t.fd(100)
        except KeyboardInterrupt:
            print("종료")
            break

main()
