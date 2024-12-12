from flask import Flask, request, jsonify, render_template
import pymysql

app = Flask(__name__)

# 데이터베이스 연결
def connect_to_db():
    return pymysql.connect(
        host='192.168.56.101',
        port=4567,
        user='root',
        password='1234',
        db='club_management',
    )

# 데이터 삽입 API
@app.route('/insert', methods=['POST'])
def insert_data():
    try:
        conn = connect_to_db()
        with conn.cursor() as cursor:
            # 요청 데이터 가져오기
            table = request.form.get('table')  # 테이블 이름
            data = request.form.to_dict()      # 전체 폼 데이터를 딕셔너리로 가져옴
            del data['table']                  # 테이블 정보는 쿼리에서 사용하지 않으므로 삭제

            # 테이블별 컬럼 정의
            columns = {
                "Member": ["MemberID", "Name", "PhoneNumber", "Grade", "FeePaid", "IsGraduate"],
                "Club": ["Name", "MemberCount"],
                "Member_Club": ["MemberID", "ClubID"],
                "Project": ["ActivityName", "StartDate", "ActivityLocation", "Client"],
                "Member_Project": ["MemberID", "ProjectID"],
                "Department": ["Name", "Professor"],
                "Member_Department": ["MemberID", "DepartmentID"],
                "Finance": ["ClubID", "ClubFee", "ActivityFee"],
                "Safety": ["ClubID", "Area", "AccidentDate", "Status"],
                "Performance": ["PerformanceName", "Description", "MemberID"]
            }

            # 입력 검증
            if table not in columns:
                return jsonify({"error": f"Unknown table: {table}"}), 400

            # 동적으로 INSERT 쿼리 생성
            table_columns = columns[table]
            placeholders = ", ".join([f"%({col})s" for col in table_columns])  # %(컬럼명)s로 매핑
            column_names = ", ".join(table_columns)
            query = f"INSERT INTO {table} ({column_names}) VALUES ({placeholders})"

            # 실행
            cursor.execute(query, data)
            conn.commit()

        return jsonify({"message": f"Data inserted into {table} successfully!"})
    except Exception as e:
        return jsonify({"error": str(e)}), 500
    finally:
        conn.close()


# 데이터 검색 API
@app.route('/search', methods=['GET'])
def search_data():
    print("\n검색할 테이블을 선택하세요:")
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

    try:
        conn = connect_to_db()
        with conn.cursor() as cursor:
            if choice == '1':
                search_key = input("검색 키워드 (이름, 학번, 전화번호 중 하나): ")
                query = "SELECT * FROM Member WHERE Name LIKE %s OR MemberID LIKE %s OR PhoneNumber LIKE %s"
                search_value = f"%{search_key}%"
                cursor.execute(query, (search_value, search_value, search_value))

            elif choice == '2':
                search_key = input("검색 키워드 (동아리 이름 또는 구성원 수): ")
                query = "SELECT * FROM Club WHERE Name LIKE %s OR MemberCount LIKE %s"
                search_value = f"%{search_key}%"
                cursor.execute(query, (search_value, search_value))

            elif choice == '3':
                search_key = input("검색 키워드 (학번 또는 동아리 ID): ")
                query = "SELECT * FROM Member_Club WHERE MemberID LIKE %s OR ClubID LIKE %s"
                search_value = f"%{search_key}%"
                cursor.execute(query, (search_value, search_value))

            elif choice == '4':
                search_key = input("검색 키워드 (활동 이름, 장소 또는 클라이언트): ")
                query = "SELECT * FROM Project WHERE ActivityName LIKE %s OR ActivityLocation LIKE %s OR Client LIKE %s"
                search_value = f"%{search_key}%"
                cursor.execute(query, (search_value, search_value, search_value))

            elif choice == '5':
                search_key = input("검색 키워드 (학번 또는 프로젝트 ID): ")
                query = "SELECT * FROM Member_Project WHERE MemberID LIKE %s OR ProjectID LIKE %s"
                search_value = f"%{search_key}%"
                cursor.execute(query, (search_value, search_value))

            elif choice == '6':
                search_key = input("검색 키워드 (부서 이름 또는 담당 교수): ")
                query = "SELECT * FROM Department WHERE Name LIKE %s OR Professor LIKE %s"
                search_value = f"%{search_key}%"
                cursor.execute(query, (search_value, search_value))

            elif choice == '7':
                search_key = input("검색 키워드 (학번 또는 부서 ID): ")
                query = "SELECT * FROM Member_Department WHERE MemberID LIKE %s OR DepartmentID LIKE %s"
                search_value = f"%{search_key}%"
                cursor.execute(query, (search_value, search_value))

            elif choice == '8':
                search_key = input("검색 키워드 (동아리 ID, 동아리 회비 또는 활동 비용): ")
                query = "SELECT * FROM Finance WHERE ClubID LIKE %s OR ClubFee LIKE %s OR ActivityFee LIKE %s"
                search_value = f"%{search_key}%"
                cursor.execute(query, (search_value, search_value, search_value))

            elif choice == '9':
                search_key = input("검색 키워드 (동아리 ID, 관리 지역 또는 사고 상태): ")
                query = "SELECT * FROM Safety WHERE ClubID LIKE %s OR Area LIKE %s OR Status LIKE %s"
                search_value = f"%{search_key}%"
                cursor.execute(query, (search_value, search_value, search_value))

            elif choice == '10':
                search_key = input("검색 키워드 (실적 이름, 설명 또는 학번): ")
                query = "SELECT * FROM Performance WHERE PerformanceName LIKE %s OR Description LIKE %s OR MemberID LIKE %s"
                search_value = f"%{search_key}%"
                cursor.execute(query, (search_value, search_value, search_value))

            else:
                print("잘못된 선택입니다.")
                return

            results = cursor.fetchall()
            if results:
                for row in results:
                    print(row)
            else:
                print("검색 결과가 없습니다.")

    except Exception as e:
        print(f"오류 발생: {e}")

    finally:
        if conn:
            conn.close()

@app.route('/delete', methods=['DELETE'])
def delete_data():
    print("\n삭제할 테이블을 선택하세요:")
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

    try:
        if choice == '1':
            member_id = input("삭제할 학번 입력: ")
            query = "DELETE FROM Member WHERE MemberID = %s"
            execute_query(query, (member_id,))

        elif choice == '2':
            club_id = int(input("삭제할 동아리 ID 입력: "))
            query = "DELETE FROM Club WHERE ClubID = %s"
            execute_query(query, (club_id,))

        elif choice == '3':
            member_id = input("삭제할 학번 입력: ")
            club_id = int(input("삭제할 동아리 ID 입력: "))
            query = "DELETE FROM Member_Club WHERE MemberID = %s AND ClubID = %s"
            execute_query(query, (member_id, club_id))

        elif choice == '4':
            project_id = int(input("삭제할 프로젝트 ID 입력: "))
            query = "DELETE FROM Project WHERE ProjectID = %s"
            execute_query(query, (project_id,))

        elif choice == '5':
            member_id = input("삭제할 학번 입력: ")
            project_id = int(input("삭제할 프로젝트 ID 입력: "))
            query = "DELETE FROM Member_Project WHERE MemberID = %s AND ProjectID = %s"
            execute_query(query, (member_id, project_id))

        elif choice == '6':
            department_id = int(input("삭제할 부서 ID 입력: "))
            query = "DELETE FROM Department WHERE DepartmentID = %s"
            execute_query(query, (department_id,))

        elif choice == '7':
            member_id = input("삭제할 학번 입력: ")
            department_id = int(input("삭제할 부서 ID 입력: "))
            query = "DELETE FROM Member_Department WHERE MemberID = %s AND DepartmentID = %s"
            execute_query(query, (member_id, department_id))

        elif choice == '8':
            club_id = int(input("삭제할 동아리 ID 입력: "))
            query = "DELETE FROM Finance WHERE ClubID = %s"
            execute_query(query, (club_id,))

        elif choice == '9':
            safety_id = int(input("삭제할 안전 관리 ID 입력: "))
            query = "DELETE FROM Safety WHERE SafetyID = %s"
            execute_query(query, (safety_id,))

        elif choice == '10':
            performance_id = int(input("삭제할 실적 ID 입력: "))
            query = "DELETE FROM Performance WHERE PerformanceID = %s"
            execute_query(query, (performance_id,))

        else:
            print("잘못된 선택입니다.")

    except Exception as e:
        print(f"오류 발생: {e}")


# 메인 HTML 페이지
@app.route('/')
def home():
    return render_template('index.html')  # HTML 파일 제공

if __name__ == '__main__':
    app.run(debug=True)
