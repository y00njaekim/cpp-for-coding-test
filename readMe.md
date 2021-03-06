## 목차

[Chapter9. 최단 경로](#chapter9-최단-경로)

[Chapter10. 그래프](#chapter10-그래프)

#### 알고리즘 유형별 기출문제

[Chapter11. 그리디문제](#chapter11-그리디문제)

[Chapter12. 구현](#chapter12-구현)

[Chapter13. DFS BFS](#chapter13-dfs-bfs)

[Chapter14. 정렬](#chapter14-정렬)

[Chapter15. 이진탐색](#chapter15-이진탐색)

[Chapter16. 다이나믹 프로그래밍](#chapter16-다이나믹-프로그래밍)

[Chapter17. 최단경로](#chapter17-최단경로)

[Chapter18. 그래프](#chapter18-그래프)

---

#### Chapter9 최단 경로

- 전보

  ✔️   ToDoList

  - `visited[]` 쓰지 말고 갱신 가능성을 바탕으로 방문 여부 판단하기 [코드설명](https://y00njaekim.github.io/algorithm/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/#%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0%EC%97%90-%EC%A1%B0%EA%B8%88-%EB%8D%94-%EA%B9%8C%EB%8B%A4%EB%A1%AD%EC%A7%80%EB%A7%8C-%EB%B9%A0%EB%A5%B4%EA%B2%8C-%EB%8F%99%EC%9E%91%ED%95%98%EB%8A%94-%EC%BD%94%EB%93%9C) 참조

<br/>

#### Chapter10 그래프

- 크루스칼

  📌  Remember

  - 간선 리스트 변수 명 `edges`

  - `node` 사이의 거리에 대한 변수 명 `cost`

  - property 가 세개 이상인 자료 구조의 경우 구조체와 `compare` function 을 만들어서 `sort` 할 수 있지만 `pair<int, pair<int, int> >` 와 같이 pair 을 중첩해서 사용할 수도 있음을 기억!

  - `parent[]` 는 `findParent()` 를 위한 수단일 뿐

    - `if(findParent(graph[i].second.first) == findParent(graph[i].second.second)) continue;`  에서 `findParent()` 대신 `parent[]` 를 참조하는 식의 방법은 틀림!

- 커리큘럼

  📌  Remember

  - next node 를 check 할 때 시간비용 갱신하면 `graphIn` , `graphOut` 구분할 필요 없음

    - ```cpp
      int nextSize = graphOut[cur].size();
      for(int j=0; j<nextSize; j++) {
       // 여기서 갱신!! 
      }
      ```

  ✔️   ToDoList

  - `prevSize`, `graphIn` 따로 만들지 말고 문제 풀기
  
---

#### Chapter11 그리디문제

- 모험가 길드

  📌  Remember

  - `priority_queue` 는 내림차순 정렬임을 기억!
  - `while` 문의 조건문과 탈출문을 헷갈리지 말자
    - `while(inGuild != maxGuild && !q.empty()) {` 에서 `&&` 과 `||` 중 당연히 `&&` 을 했어야 했는데.

  ✔️   ToDoList

  - 다음에는 `queue` 말고 `vector` 이용하기
    - `while` 문의 조건으로 이용하는 `queue.empty()` 와 `for` 문을 이용한 `vector` 의 순회는 둘 다 끝이 있다는 점에서 동일


- 만들 수 없는 금액

  ❓ Question

  - 이게 왜 그리디 알고리즘으로 분류되는 걸까.


- [무지의 먹방 라이브](https://github.com/y00njaekim/cpp-for-coding-test/blob/master/ch11_greedy/eating_show.md)

<br/>

#### chapter12 구현

- 자물쇠와 열쇠

  📌  Remember

  - `vector` 초기화 방법

    1. 5X5 Matrix 만들기: `vector<vector<int> > result(5, vector<int>(5))`
    2. 0으로 초기화된 5X5 Matrix 만들기: `vector<vector<int> > result(5, vector<int>(5, 0))`

  - Matrix 90도 회전 방법: 1. transpose 2. 행기준 뒤집기

    ```cpp
    for(int r=0; r<행길이; r++) {
        for(int c=0; c<열길이; c++) {
            res[c][열길이-1-r] = v[r][c]; // r, c -> c, r -> c, vSize-1-r
        }
    }
    ```

- 뱀

  📌  Remember

  - 손으로 미리 구조를 다 짠 후에 코딩을 시작해야 할 듯

    ```cpp
    if(dir.front().first == t) {
      if(dir.front().second == 'L') {
        d--;
        if(d < 0) d += 4; 
      }
      else if(dir.front().second == 'D') {
        d++;
        d = d % 4;
      }
      dir.pop();
    }
    
    next = make_pair(cur.first+dr[d], cur.second+dc[d]);
    ```

    이렇게 짜야하는 걸 (`d` 갱신 이후 `next` 갱신에서 `d` 사용)

    ```cpp
    next = make_pair(cur.first+dr[d], cur.second+dc[d]);
    
    if(dir.front().first == t) {
      if(dir.front().second == 'L') {
        d--;
        if(d < 0) d += 4; 
      }
      else if(dir.front().second == 'D') {
        d++;
        d = d % 4;
      }
      dir.pop();
    }
    ```

    이렇게 짜버렸다. (`d` 갱신 하기도 전에 `next` 갱신에서 `d` 사용)

    잘 안보였다. 디버깅이 힘들었다. 해결 방법으로 생각나는게 손으로 먼저 짜기 시작하지 말고 머리로 구상을 다 한 후에 짜는 게 어떨까 싶다.

  - `-1 % 4` 값은 `-1` 이다..
  
- 기둥과 보 설치

  📌  Remember

  - 복붙할 때 내가 그 코드 왜 썼는지 생각하고 완전하게 같은 상황이 아니라면 해당 코드 수정하기
  - 벽 등의 구조물을 배열로 구현할 때, `segmentation fault` 유의하기
    - `if` 문과 `continue` 잘 이용하기
    - 배열 크기 가로 세로 세 배 해서 가운데 배열만 이용하기
  
- 치킨 배달

  📌  Remember

  - [조합 참고 블로그](https://cutemoomin.tistory.com/entry/c-nextpermutation-%EC%A1%B0%ED%95%A9-%EA%B5%AC%ED%95%98%EA%B8%B0) (`next_permutation`  사용) (블로그와 나동빈님 코드는 아래 부분에서 다름)

    ```cpp
    vector<bool> binary(chicken.size());
    fill(binary.end() - m, binary.end(), true);
    ```

    [사용 시 주의사항](https://mjmjmj98.tistory.com/38) (ex. **오름차순으로 정렬**된 경우만 사용 가능) ➡️ 원리도 이 '오름차순' 과 연관이 있을 것이라 추측

  - `int min = *min_element(vec.begin(), vec.end());`

- 외벽 점검

  - **너무 어려워서 일단 스킵 다음에 다시 트라이**

<br/>

#### Chapter13 DFS BFS

- 특정 거리의 도시 찾기

  📌  Remember

  - 내가 생각한 결과와 답이 다를 때 적극적으로 디버깅하기
    - 적극적 디버깅이란 console print out 많이 해보기 & 손으로 그려가며 따라가기
    - 이 문제도 DFS 로 접근했다가 그림그려보니까 바로 BFS 인거 깨달음
  - **Depth 판단은 BFS 로 해야한다!**
    - DFS 로 하면 depth 가 깊어도 일단 들어간 다음 `visited = true` 처리 되므로 실제의 depth 판단하기 위한 접근 과정에서 `visited == true` 조건에 막혀 접근 못함
  - `visited == false` 판단하는 타이밍 & `visited = true` 할당하는 타이밍
    -  `visited == false` 판단하는 타이밍
      - 입국 심사라고 생각하자. 해당 노드가 `queue` 에 들어와도 될지 안될지 판단하는 순간에서 검사하자.
    - `visited = true` 할당하는 타이밍
      - `queue` 라는 국가에 입국했다고 생각하자.
        - ❌ (이 타이밍 아님) 해당 노드가 찐 주인공이 되는 순간 = 그 노드의 `adj` 를 판단하기 위해 주목해주는 순간.
        - ⭕ (이 타이밍 맞음) 해당 노드가 `queue` 에 들어온 직후의 순간.

- 연구소

  📌  Remember

  - DFS 혹은 BFS 의 **매개변수**로 대개 **시작 노드**가 들어가야 한다.

  - 상 하 좌 우 대각 뒤질 때 `seg fault` 주의하자!!

  - 상 하 좌 우 는 `(0, 1), (0, -1), (1, 0), (-1, 0)` 이다. `(1, 1), (-1, 1), (1, -1), (-1, -1)` 이 아니다.

  - 2차원 배열의 열과 행을 1차원 배열에서 결정할 때 1차원 배열의 인덱스를 2차원 배열의 **column num** 으로 나누어야 한다.

    ```cpp
    for(int i=0; i<N*M; i++) {
    	if(binary[i]) {
    		int _r = i / M;
    		int _c = i % M;
    		cand.push_back(make_pair(_r, _c));
    	}
    ```

  - DFS 할 때 next node 표현

    - 나동빈 님

      ```cpp
      void virus(int x, int y) {
          for (int i = 0; i < 4; i++) {
              int nx = x + dx[i];
              int ny = y + dy[i];
      ```

    - 나

      ```cpp
      for(int i=0; i<4; i++) {
          pii next = make_pair(X.first+dx[i], X.second+dy[i]);
      ```

    `nx` `ny` 가 더 좋은 표현인 것 같다.

  - [DFS BFS 시간 복잡도](https://velog.io/@kjh107704/%EA%B7%B8%EB%9E%98%ED%94%84-BFS%EC%99%80-DFS)

  <br/>

  ✔️   ToDoList

  - 사실 `visited` 가 필요 없는 문제 -> 다음에는 `visited ` 안 쓰고 풀기
  - 조합을 이용해 울타리 설치하는 방법 아주 좋았음. 다음에는 `DFS` 를 이용하여 울타리 설치하기.
    - 어떻게 보면 조합이랑 `DFS` 랑 느낌이 살짝 유사한 감이 있네 ??

- 경쟁적 전염

  📌  Remember

  - 구조체 `operator` override 하는 방법 (출처: [나동빈님 깃허브](https://github.com/ndb796/python-for-coding-test/blob/master/13/3.cpp))

- 연산자 끼워 넣기

  📌  Remember

  - **DFS BFS 는 본질적으로 완전탐색이다.**

- 감시 피하기

  📌  Remember

  - DFS 의 parameter 로서 `DFS (노드) ` 와 같은 형태 or `DFS (depth)` 같은 형태가 올 수 있다.
    이 때 `d++; dfs(d)` 와 같이 할 수도 있고 아니면 그냥 `dfs(d+1)` 과 같이 할 수도 있다.

  - DFS 탐색 방법으로

    1. `map` 글로벌 선언
       => `DFS()` 를 이용한 탐색 이전 `map` 변경 
       => `DFS()` 에서 원하는 결과 도출 실패시 스택에서 `DFS ()` 뽑아 냄.
       => 스택 제거하며 `map` 은 조작 이전으로 복구 시켜놓음.

       ```cpp
       map[r][c] = '변경'
       DFS();
       map[r][c] = '변경이전'
       ```

    2. `DFS()` 의 파라미터에 로컬로 선언한  `newMap` (= 조작된 `map`) 을 넣고 굳이 복구 안시킴.

       ```c++
       newMap = map;
       newMap[r][c] = '변경';
       DFS(newMap);
       ```

    - 이 때 `newMap` 은 **완전탐색을 시도하는 횟수 만큼** 만들어야 한다. 즉 모든 탐색에 대하여 새로운 `newMap` 을 제공해주어야 한다.

- 인구 이동

  📌  Remember

  - 상하좌우 + 특정 조건으로 adjacent 판단할 때는 미리 만들 필요가 없다. 그냥 바로 판단하자

- 블럭 이동하기

  📌  Remember

  - [[나동빈님 코드]](https://github.com/ndb796/python-for-coding-test/blob/master/13/8.cpp) 를 살펴보면
    - bfs 코드를 작성할 때 adjcent 만드는 function `getNextPos()` 코드를 따로 작성하였다. 이 때, `getNexPos()` 의 반환형은 `vector<Node> nextPos` 로 `getNextPos()` 밖의 bfs 에서 `for(int i=0; i<nextPos.size(); i++)` 를 이용해서 adjacent 에 접근한다.
    - adjcent 를 만들 때는 `visited` 여부를 판단하지 않는다. `visited` 판단은 만들어진 adjcent 를 `for` 문을 통해 접근하는과정에서 발생한다. 
    - **나의 코드와의 차이** ) 나는 `visited` 를 따로 고려하지 않았다. 사실 이래도 시간이 오래 걸릴 뿐 문제가 풀리긴 한다. 하지만 depth 가 1만큼 깊어질 때 마다 가능한 adj 의 최대 크기만큼, 즉 8 배만큼 늘어난다.
    - `visited` 를 기존과 같이 작성할 수 없다. 즉 bool 형태의 2차원 배열로서 `visited` 를 만들 수 없다. 때문에 그냥 vector 형태로 만들어 방문한 노드를 vector 에 push 한 다음, 특정 노드의 `visited` 여부를 판단하려 할 때, linear search 하며 같은 element 가 있는지 판단하면 된다.

  ✔️   ToDoList

  - 틀렸음. 못풀었음. 틀린 코드 github 에 푸쉬 해놨으니, 일단 프로그래머스로 다시 풀고 나서 내가 작성한 코드의 틀린 이유 꼭 알아내기.

#### Chapter14 정렬

- 국영수

  📌  Remember

  - struct 정렬 [[참고]](https://it-earth.tistory.com/129) vs class 정렬 [[참고]](https://github.com/ndb796/python-for-coding-test/blob/master/14/1.cpp)
  - `endl` **절 대 쓰 지 마.** `'/n'` **절 대 써.**

  ✔️   ToDoList

  - class 정렬 코드 mac terminal g++ 쓰니까 안됨. 컴파일러 버전, c++ 버전 문제 해결 필요

- 안테나

  📌  Remember

  - 나 통계 이해 부족한 듯. 원래 중앙값 유래가 모든 통계값과 참값의 오차 합의 최소가 되는 값이래.. [[중앙값 설명 유튜브]](https://www.youtube.com/watch?v=UiVL9k0XbY8)

- 실패율

  📌  Remember

  - 문제에서 준 크기 `N` 으로 `vector` `resize` 했을 때, 그 값 참조하려면 `v.size()` 처럼 쓰지 말고 그냥 `N` 으로 쓰기

#### Chapter15 이진탐색

- 정렬된 배열에서 특정 수의 개수 구하기

  📌  Remember

  - `<algorithm>` 에 `upper_bound` 와 `lower_bound` 라는 함수가 있음. [[Reference]](https://www.cplusplus.com/reference/algorithm/upper_bound/)
  - 유튜브 횡설수설 [[링크]](https://youtu.be/tkWW6ZcD7Rs)

  ✔️   ToDoList

  - `<algorithm>` 에 `upper_bound` 와 `lower_bound` 라는 함수 사용해서 풀기.

- 공유기 설치

  📌  Remember

  - **파라메트릭 서치 (Parametric Search)** 

    - 최적화 문제를 결정 문제로 치환하여 해결하는 기법.

      - 최적화 문제 : 문제의 **상황을 만족**하는 특정 변수의 최솟/최댓값을 구하는 문제
      - 결정 문제 :  YES / NO

    - 특징

      🎯 원하는 조건을 만족하는 **가장 알맞는** 값을 찾는 문제에 주로 사용

      🎯 가능한 답의 범위가 이산적이거나 답에 대한 허용 오차범위가 존재하야 파라메트릭 서치로 풀이 가능

      🎯 최솟값을 구하는 경우 최솟값이 x 라면, x 이상의 값에 대해서는 모두 조건을 만족해야 함

      🎯 최댓값을 구하는 경우 최댓값이 x 라면, x 이하의 값에 대해서는 모두 조건을 만족해야 함

      🎯 밑에 글과 함께 배스킨 라빈스 알바를 생각하자 !

  - 파라메트릭 서치도 결국 탐색이다. 탐색 범위가 1,000 만 (10^7) 이상으로 넘어가면 이진 탐색과 같이 O(logN) 의 속도를 내는 알고리즘을 이용해야 한다.

    - ❗ 이 문제에서 탐색 범위는 [1, N] 이다. 이걸 문제푸는 과정에서 분명하게 인지해야 한다.

  - 이진 탐색 이전에 항상 정렬하는 것을 잊지 말자.

    


> 예를 들어 당신이 정육점 주인인데, 손님이 고기 200g을 달라고 해서 고기 덩이에서 200g을 잘라내야 한다고 해보자. 첫 번째 방법으로 이를 해결하려면, 고기의 밀도, 지방 비중, 마블링 정도 등을 분석한 뒤 얼마나 잘라야 정확히 200g이 되는지를 계산하여 딱 그만큼 잘라야 한다.
>
> 그러나 실제로 이렇게 하기엔 굉장히 어렵다. 따라서 일반적으로는 대략 눈대중으로 어느정도 잘라서 저울에 재본 후, 200g보다 부족하면 조금 더 잘라 넣고 200g을 넘치면 조금 잘라서 때낸 뒤 다시 저울에 재보는 식으로 한다. 즉, 우리는 **“고기 200g를 잘라라”**라는 문제를 **“지금 자른 고기가 200g보다 가벼운가/무거운가”**라는 결정문제로 변형을 한 뒤 고기를 조금 추가하거나 덜어내면서 이분탐색을 하는 두 번째 방법으로 문제를 해결한다. 이렇게 원래 주어진 문제를 **결정문제로 변형하여 이분탐색을 통해 해결**하는 것을 **파라매트릭 서치**라고 한다.
>
>  출처 - [ialy's blog](https://ialy1595.github.io/post/parametric-search/)

<br/>

- 가사 검색

  📌  Remember

  - 여기서 사용할 수 있는 c++ method
    - `upper_bound`, `lower_bound` [[Reference]](https://www.cplusplus.com/reference/algorithm/upper_bound/)
    - `find` [[Reference]](https://www.cplusplus.com/reference/string/string/find/)
    - `replace` [[Reference]](https://www.cplusplus.com/reference/string/string/replace/)
    - `reverse` [[Reference]](https://www.cplusplus.com/reference/algorithm/reverse/)

  - Binary Search

    - binary search 에서 `low` 또는 `high` 의 parameter 로서 `mid+1` 을 쓸 거면 무조건 `mid = (low + high - 1) / 2` 와 같이 좌편향을 설정해야 한다. 🙎‍♂️ 아마 ?..
    - search 대상이 탐색되지 않았을 때는 `-1` 을 return 한다. 이 때 **1. 좌편향 미드 사용**시 `if(low == mid)` 의 경우를 잘 이용해야 하고 **2. 우편향 미드 사용시**에는 `if(mid+1 == high)` 의 경우를 잘 살펴보아야 한다. 위의 두 경우가, 검색 결과가 없을 때  `-1` 을 리턴하는 상황을 고려하지 않는 코드에서 무한 루프를 야기하는 경우이다.
    - binary search 에서 세가지 경우 1. `mid == tar` 2. `mid > tar` 3. `mid < tar` 에 대하여 재귀적으로 binary search 를 진행할 때 **반드시 return** 을 함께 이용해야 한다. return 을 안쓴 경우를 생각해보자. binary search 의 첫 호출 시 위의 세가지 경우 하나에 해당하여 재귀적으로 binary search 를 진행할 것이다. 만약 바로 그 다음의 호출에서 `mid == tar` 의 경우가 성립되어 특정 `mid` 를 return 하며 함수가 종료된다 했을 때 그 `mid` 가 재귀 호출 스택 bottom 함수에 넘어간 후 공중에서 사라진다. 왜냐하면 그 함수로 `mid` return 되어 넘어간다 할지라도 그 값을 그 어디에서도 return 하지 않기 때문이다.

  - While

    - `while` 문은 `for` 문과 달리 `i++` 과 같은 조건을 직접적으로 설정해주어야 한다. 이 때, 이 `i` 값을 갱신하는 코드가 모든 `do` 파트에 대해서 항상 실행되어야 한다. 내가 저지른 실수는 `i++` 을 갱신하는 코드 이전에 특정 상황에 대하여 `continue` 를 작성했다는 것인데, 이로 인해 특정 경우에는 `i++` 과 같은 갱신이 발생하지 않게 되고 결국 `i` 는 그대로이기 때문에 `continue`  가 발생하는 `do` 파트가 무한 루프에 빠지게 되는 문제가 발생한다.
    - 언제나 처음과 끝의 케이스는 두번 생각하고 코드를 짜야 한다. `segmentation fault` 도 유의해야 한다.

    - 내가 또 저지른 실수가 나는 `while` 문 안의 조건으로서 `while(nextWord 어쩌구)` 와 같이 `nextWord` 를 이용하였는데, 이 `nextWord` 가 모든 `do` 에서 생성되지 않는 치명적인 오류가 있었다. 특정 경우에는 `continue` 로 인해 `nextWord` 가 생성되기도 전에 `do` 가 끝나기도 하고 그랬다.

  ✔️   ToDoList

  - c++ method 
  - `upper_bound`, `lower_bound`, `find`, `replace`, `reverse` 이용해서 풀기

#### Chapter16 다이나믹 프로그래밍

- 정수 삼각형

  📌  Remember

  - dpTable 만들 때 예외 처리 방법 (`segmentation fault` 등 주의)

    1. 삼중 `for` 문 + `continue`

       🔑 보다 작은 문제를 살펴볼 때, 즉 dpTable 에서 이전 값들을 참조할 때 값들을 `for` 문을 이용하여 참조하기 [[예시]](https://github.com/y00njaekim/cpp-for-coding-test/blob/master/ch16_dp/gold.cpp)

    2. 이중 `for` 문 + `if`

       🔑 dpTable 에서 참조할 변수가 `segmentation fault` 를 일으킬 가능성이 없으면 그냥 참조. 있으면 `0` 으로 선언 [[예시]](https://github.com/y00njaekim/cpp-for-coding-test/blob/master/ch16_dp/tri.cpp)

- 퇴사

  📌  Remember

  - DP 문제 전반적인 아이디어 [[링크]](https://y00njaekim.github.io/algorithm/%EB%8B%A4%EC%9D%B4%EB%82%98%EB%AF%B9%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D/)

  - DP 점화식 세웠을 때 그거의 정당성을 꼭 생각해 보아야 함
    - 흔히 실수할 수 있는 케이스에 대해 주저리주저리 [[유튜브]](https://youtu.be/7z_YHI7P0t4)
  - `bottomOne` `topOne` 이라는 변수명 괜찮은 듯

- 병사 배치하기

  📌  Remember

  - **최장 증가 부분 수열 이라는 다이나믹 프로그래밍** 유형
    - dp[i] = array[i] 를 마지막 원소로 가지는 부분 수열의 최대 길이
    - 모든 0 <= j < i 에 대하여 dp[i] = max(dp[i], dp[j]+1) if array[j] < array[i]
  - 파악하기 어려운 Dp 문제의 특징 : `dp[i]` = `func(dp[i-1], dp[i-2])` 등 이 아니라 `func(dp[j]), j=1, 2, ... , i-1` 과 같은 식일 때. 즉 직전의 작은 문제가 아니라 어느 작은 문제로부터 파생될지 모를 때.

- 편집 거리

  📌  Remember

  - 이차원 배열로 만든 dpTable ..

#### Chapter17 최단경로

- 플로이드

  📌  Remember

  - 플로이드 알고리즘에 대한 오해와 정당성 확보의 직관적 느낌 [[유튜브]](https://y00njaekim.github.io/algorithm/%ED%94%8C%EB%A1%9C%EC%9D%B4%EB%93%9C%EC%9B%8C%EC%85%9C/)

- 숨바꼭질

  📌  Remember

  - **다익스트라 알고리즘** 유의사항

    - 최단경로의 길이 `vector` 변수명 : `d`

    - `priority_queue` 이용할 때 `-` 부호는 항상 유의하자

    - `adj` : 그래프 인접 노드 정보가 들어간 `vector<vector<int> >` 가 존재한다.

    - 초기값 설정할 때 `priority_queue` 와 `d` 모두 이용해 주어야 함

      ```cpp
      pq.push({0, start});
      d[start] = 0;
      ```

    - 갱신 가능성을 바탕으로 `visited` 대체할 때 부등호의 등호 포함 여부는 매우 중요

      ```cpp
      if (d[now] < dist) continue; // O
      
      if (d[now] <= dist) continue; // X
      ```

      왜냐하면 이렇게 했을 때 초기값을 넣은 `pq.top().second(=dist)` 이 `d[now]` 와 같기 때문에 처음부터 `continue` 가 발생하여 `while` 문이 `pq.empty()` 에 의해 종료된다.

    - `pq.push()` 타이밍에 관하여. 최단거리 확정 순간의 선행 조건은 해당 노드가 `pq` 에 들어와 있다는 것이다. 즉 최단거리 확정 순간에서 `pq.push()` 를 해야하나 고민하는 것은 말도 안된다. `pq.push()` 의 타이밍은 `adj` 를 검사하는 순간이다.

#### Chapter17 최단경로

- 탑승구

  📌  Remember

  - 이걸 union-find 자료구조로 해결하네 대박.

- 어두운 길

  📌  Remember

  - 크루스칼 알고리즘 할 때 굳이 priority_queue 를 쓸 필요가 없네. 그냥 vector 로 하나하나 다 체크하면 됨.

- 탑승구

  📌  Remember

  - **와 이걸 위상 정렬을 사용해서 푸네**

    🔥 직관 🔥

    - 위상 정렬 그래프를 잘 보면
      <img src="https://user-images.githubusercontent.com/56385667/147236128-6c2c9a0f-290a-4418-a6a7-576f55b16338.png"/>
      자료구조가 알고리즘의 선수 과목이고,
      알고리즘이 고급 알고리즘의 선수 과목이라,
      자연스레 자료구조가 고급 알고리즘의 선수과목이 되는 느낌을 기억해야 함
    - 특정 행동을 1등이 해야 2등이 할 수 있고, 2등이 해야 3등이 할 수 있는 구조. ➡️ 여기서는 1등이 출력되어야 2등이 출력될 수 있고, 2등이 출력되어야 3등이 출력될 수 있는 구조로 생각하자.

  - `vector` `erase` **사용 방법**

    ```cpp
    	iterator erase( iterator pos );
    
      v.erase(v.begin() + index);
    ```

  - **위상정렬 Detail**

    1. 가장 기본적인 위상정렬 형태 🔑 `while` 문의 조건으로 `!q.empty()` 이용 [[코드]](https://github.com/ndb796/python-for-coding-test/blob/master/10/6.cpp)
    2. 이 문제에서 모범적인 위상정렬 형태 🔑 정확하게 노드 개수만큼 `for` 문 돌리는 방법 이용 [[코드]](https://github.com/ndb796/python-for-coding-test/blob/master/18/5.cpp)
       1. 위상 정렬에서 말하는 cycle : 이러지도 저러지도 못하는 상태 ➡️ `ind == 0` 인게 없는 상황
    3. 내 코드 🔑 이유 없는 `do-while` 문 사용 [[코드]](https://github.com/y00njaekim/cpp-for-coding-test/blob/master/ch18_graph/rank.cpp)
       1. `do-while` 문과 `while` 문의 차이는 딱 첫 번째 케이스에서 `while` 문 조건을 만족하냐 하지 않냐 의 차이. 내 코드의 경우 `do-while` 을 쓸 이유가 전혀 없음
