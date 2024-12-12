# import pymysql

# conn = pymysql.connect(
#     host='192.168.56.101', 
#     port=4567,
#     user='root', 
#     password='1234', 
#     db='madang', 
# )

# try:
#     # 연결 성공 시
#     with conn.cursor() as cursor:
#         # 실행할 쿼리
#         query = "SELECT * FROM Book"  # 예제: books 테이블에서 모든 데이터를 가져옴
#         cursor.execute(query)

#         # 결과 가져오기
#         results = cursor.fetchall()

#         # 결과 출력
#         print("Book 테이블 데이터:")
#         for row in results:
#             print(row)

# finally:
#     # 연결 종료
#     conn.close()

import pymysql

def connect_to_db():
    """MySQL 데이터베이스 연결"""
    return pymysql.connect(
        host='192.168.56.101', 
        port=4567,
        user='root', 
        password='1234', 
        db='club_management', 
    )

def insert_into_table(conn):
    """데이터 삽입 기능"""
    try:
        with conn.cursor() as cursor:
            print("\n삽입할 테이블을 선택하세요:")
            print("1. Member")
            print("2. Club")
            print("3. Member_Club")
            print("4. Project")
            print("5. Member_Project")
            print("6. Department")
            print("7. Member_Department")
            print("8. Finance")
            print("9. Safety")
            print("10. Performance")

            choice = input("테이블 번호 입력: ")

            if choice == '1':
                member_id = input("학번 입력: ")
                name = input("이름 입력: ")
                phone = input("전화번호 입력: ")
                grade = int(input("학년 입력: "))
                fee_paid = bool(int(input("회비 납부 여부 (1: 납부, 0: 미납): ")))
                is_graduate = bool(int(input("졸업 여부 (1: 졸업, 0: 미졸업): ")))

                query = "INSERT INTO Member (MemberID, Name, PhoneNumber, Grade, FeePaid, IsGraduate) VALUES (%s, %s, %s, %s, %s, %s)"
                cursor.execute(query, (member_id, name, phone, grade, fee_paid, is_graduate))

            elif choice == '2':
                name = input("동아리 이름 입력: ")
                member_count = int(input("구성원 수 입력: "))

                query = "INSERT INTO Club (Name, MemberCount) VALUES (%s, %s)"
                cursor.execute(query, (name, member_count))

            elif choice == '3':
                member_id = input("학번 입력: ")
                club_id = int(input("동아리 ID 입력: "))

                query = "INSERT INTO Member_Club (MemberID, ClubID) VALUES (%s, %s)"
                cursor.execute(query, (member_id, club_id))

            elif choice == '4':
                activity_name = input("활동 이름 입력: ")
                start_date = input("시작 날짜 입력 (YYYY-MM-DD): ")
                activity_location = input("활동 장소 입력: ")
                client = input("클라이언트 입력: ")

                query = "INSERT INTO Project (ActivityName, StartDate, ActivityLocation, Client) VALUES (%s, %s, %s, %s)"
                cursor.execute(query, (activity_name, start_date, activity_location, client))

            elif choice == '5':
                member_id = input("학번 입력: ")
                project_id = int(input("프로젝트 ID 입력: "))

                query = "INSERT INTO Member_Project (MemberID, ProjectID) VALUES (%s, %s)"
                cursor.execute(query, (member_id, project_id))

            elif choice == '6':
                name = input("부서 이름 입력: ")
                professor = input("담당 교수 입력: ")

                query = "INSERT INTO Department (Name, Professor) VALUES (%s, %s)"
                cursor.execute(query, (name, professor))

            elif choice == '7':
                member_id = input("학번 입력: ")
                department_id = int(input("부서 ID 입력: "))

                query = "INSERT INTO Member_Department (MemberID, DepartmentID) VALUES (%s, %s)"
                cursor.execute(query, (member_id, department_id))

            elif choice == '8':
                club_id = int(input("동아리 ID 입력: "))
                club_fee = float(input("동아리 회비 입력: "))
                activity_fee = float(input("활동 비용 입력: "))

                query = "INSERT INTO Finance (ClubID, ClubFee, ActivityFee) VALUES (%s, %s, %s)"
                cursor.execute(query, (club_id, club_fee, activity_fee))

            elif choice == '9':
                club_id = int(input("동아리 ID 입력: "))
                area = input("안전 관리 지역 입력: ")
                accident_date = input("사고 날짜 입력 (YYYY-MM-DD): ")
                status = input("사고 상태 입력: ")

                query = "INSERT INTO Safety (ClubID, Area, AccidentDate, Status) VALUES (%s, %s, %s, %s)"
                cursor.execute(query, (club_id, area, accident_date, status))

            elif choice == '10':
                performance_name = input("실적 이름 입력: ")
                description = input("설명 입력: ")
                member_id = input("학번 입력: ")

                query = "INSERT INTO Performance (PerformanceName, Description, MemberID) VALUES (%s, %s, %s)"
                cursor.execute(query, (performance_name, description, member_id))

            else:
                print("잘못된 선택입니다.")
                return

            conn.commit()
            print("데이터 삽입 성공!")

    except Exception as e:
        print(f"오류 발생: {e}")

def search_in_table(conn):
    """검색 기능"""
    try:
        with conn.cursor() as cursor:
            print("\n검색할 테이블을 선택하세요:")
            print("1. Member")
            print("2. Club")
            print("3. Project")

            choice = input("테이블 번호 입력: ")

            if choice == '1':
                search_key = input("검색 키워드 (이름, 학번, 전화번호 중 하나): ")
                query = "SELECT * FROM Member WHERE Name LIKE %s OR MemberID LIKE %s OR PhoneNumber LIKE %s"
                search_value = f"%{search_key}%"
                cursor.execute(query, (search_value, search_value, search_value))

                results = cursor.fetchall()
                for row in results:
                    print(row)

            elif choice == '2':
                club_name = input("동아리 이름 입력: ")
                query = """
                    SELECT Member.* 
                    FROM Member 
                    JOIN Member_Club ON Member.MemberID = Member_Club.MemberID 
                    JOIN Club ON Club.ClubID = Member_Club.ClubID 
                    WHERE Club.Name = %s
                """
                cursor.execute(query, (club_name,))

                results = cursor.fetchall()
                for row in results:
                    print(row)

            elif choice == '3':
                project_name = input("프로젝트 이름 입력: ")
                query = "SELECT * FROM Project WHERE ActivityName LIKE %s"
                cursor.execute(query, (f"%{project_name}%",))

                results = cursor.fetchall()
                for row in results:
                    print(row)

            else:
                print("잘못된 선택입니다.")

    except Exception as e:
        print(f"오류 발생: {e}")

def delete_from_table(conn):
    """삭제 기능"""
    try:
        with conn.cursor() as cursor:
            print("\n삭제할 테이블을 선택하세요:")
            print("1. Member")
            print("2. Club")
            print("3. Project")

            choice = input("테이블 번호 입력: ")

            if choice == '1':
                member_id = input("삭제할 학번 입력: ")
                query = "DELETE FROM Member WHERE MemberID = %s"
                cursor.execute(query, (member_id,))

            elif choice == '2':
                club_id = int(input("삭제할 동아리 ID 입력: "))
                query = "DELETE FROM Club WHERE ClubID = %s"
                cursor.execute(query, (club_id,))

            elif choice == '3':
                project_id = int(input("삭제할 프로젝트 ID 입력: "))
                query = "DELETE FROM Project WHERE ProjectID = %s"
                cursor.execute(query, (project_id,))

            else:
                print("잘못된 선택입니다.")
                return

            conn.commit()
            print("데이터 삭제 성공!")

    except Exception as e:
        print(f"오류 발생: {e}")

def main():
    print("------------------------------------------------------------")
    print("1. connection 2. insert data 3. search data 4. delete data 5. quit")
    print("------------------------------------------------------------")

    conn = None

    while True:
        choice = input("옵션 선택: ")

        if choice == '1':
            try:
                conn = connect_to_db()
                print("데이터베이스 연결 성공!")
            except Exception as e:
                print(f"데이터베이스 연결 실패: {e}")

        elif choice == '2':
            if conn:
                insert_into_table(conn)
            else:
                print("먼저 데이터베이스에 연결하세요.")

        elif choice == '3':
            if conn:
                search_in_table(conn)
            else:
                print("먼저 데이터베이스에 연결하세요.")

        elif choice == '4':
            if conn:
                delete_from_table(conn)
            else:
                print("먼저 데이터베이스에 연결하세요.")

        elif choice == '5':
            if conn:
                conn.close()
            print("프로그램 종료.")
            break

        else:
            print("잘못된 입력입니다. 다시 시도하세요.")


if __name__ == "__main__":
    main()