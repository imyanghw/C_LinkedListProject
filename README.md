# C_LinkedListProject
주소록 관리 프로그램
> 연결리스트를 활용하여 사용자 데이터를 관리한다. 

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
> 시나리오 : 신규고객 양동이라는 사람이 비디오를 대여, 반납을 진행한다.  
시나리오 테스트를 위하여 대여일자를 8일전으로 시간을 세팅하고 반납일자를 현재시간으로 세팅하여     
하루 연체가 진행되어 연체 1일에 해당하는 요금을 안내한다. 
>>[비디오 대여 관리.pdf](https://github.com/imyanghw/C_MiniProject/files/6149102/default.pdf)

## 프로젝트 고찰
구조체를 사용하여 기능에 해당하는 멤버 변수들을 관리하기 용이하고 메뉴방식의<br>
스위치 프로그래밍 방식과 각 기능별 함수로 분리작업하여 유지보수의 가독성이 높아졌다.<br>
개선해야할 상황은 예외처리 부분이 좀 아쉬웠던 것 같다.<br>
비디오의 대여가 첫번째로 빌려간사람이 첫번째로 반납한다는 보장이 없기 때문에<br>
대여 부분에 있어서 처리하기가 어려워 대여정보는 한 정보만 나타날 수 있도록 처리하였다.<br> 
또한 고객정보나 비디오정보의 삭제 기능을 구현하는 로직이 상당히 까다롭고 코드도 어렵기 때문에<br>
구조체 정보를 활용하기 위해선 연결리스트의 사용이 좀 더 프로그램 작성에 있어서 유용할 것 같다.<br>
한눈에 보기 쉬운 코드와 간단한 로직만으로 프로그램을 작성해보자라는 취지에는 부합했지만<br> 
세부 기능사항들이 아쉬운 프로그램이다.

