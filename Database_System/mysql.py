import pymysql

conn = pymysql.connect(
    host='192.168.56.101', 
    port=4567,
    user='root', 
    password='1234', 
    db='madang', 
)

try:
    # 연결 성공 시
    with conn.cursor() as cursor:
        # 실행할 쿼리
        query = "SELECT * FROM Book"  # 예제: books 테이블에서 모든 데이터를 가져옴
        cursor.execute(query)

        # 결과 가져오기
        results = cursor.fetchall()

        # 결과 출력
        print("Book 테이블 데이터:")
        for row in results:
            print(row)

finally:
    # 연결 종료
    conn.close()