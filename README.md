# C_LinkedListProject
주소록 관리 프로그램
> 연결리스트를 활용하여 사용자 데이터를 관리

## 개발환경 및 사용버전
- Visual Studio 2017
- C Language

## 구현내용
- 주소록에 등록된 데이터 조회
- 사용자 정보 추가
- 사용자 찾기
- 사용자 삭제
- 주소록에 등록된 데이터 이름순으로 오름차순 정렬
- 입력데이터 파일에 저장

## Dataflow
<img src="https://user-images.githubusercontent.com/76413580/111422553-39a28980-8732-11eb-9a61-1244867263c6.png"></image>

## Screenshots
>[주소록 관리.pdf](https://github.com/imyanghw/C_LinkedListProject/files/6154504/default.pdf)

## 프로젝트 고찰
문제점
> 프로그램 재시작시에 파일에 기존에 기록된 데이터를 덮어씀<br>

해결
> 기존 데이터를 유지할 수 있도록 프로그램 시작시에 파일을 읽어오도록 코드를 수정함<br>

프로그램 장/단점
- 연결리스트를 활용하여 연결리스트의 장점인 데이터의 삽입과 삭제가 용이함
- 코드가 직관적임
- 세부적인 기능사항을 구현하고자 할 때 설계가 복잡함
