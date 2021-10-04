## 목차

[Chapter9. 최단 경로](#chapter9.-최단-경로)

[Chapter10. 그래프](#chapter10.-그래프)

#### 알고리즘 유형별 기출문제

[Chapter11. 그리디문제](#chapter11.-그리디문제)

---



</br>

#### Chapter9. 최단 경로

- 전보

  ✔️   ToDoList

  - `visited[]` 쓰지 말고 갱신 가능성을 바탕으로 방문 여부 판단하기 [코드설명](https://y00njaekim.github.io/algorithm/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/#%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0%EC%97%90-%EC%A1%B0%EA%B8%88-%EB%8D%94-%EA%B9%8C%EB%8B%A4%EB%A1%AD%EC%A7%80%EB%A7%8C-%EB%B9%A0%EB%A5%B4%EA%B2%8C-%EB%8F%99%EC%9E%91%ED%95%98%EB%8A%94-%EC%BD%94%EB%93%9C) 참조

#### Chapter10. 그래프

- 크루스칼

  📌  Remember

  - 간선 리스트 변수 명 `edges`

  - `node` 사이의 거리에 대한 변수 명 `cost`

  - property 가 세개 이상인 자료 구조의 경우 구조체와 `compare` function 을 만들어서 `sort` 할 수 있지만 `pair<int, pair<int, int> >` 와 같이 pair 을 중첩해서 사용할 수도 있음을 기억!

  - `parent[]` 는 `findParent()` 를 위한 수단일 뿐

    - `if(findParent(graph[i].second.first) == findParent(graph[i].second.second)) continue;`  에서 `findParent()` 대신 `parent[]` 를 참조하는 식의 방법은 틀림!

<br/>

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



#### Chapter11. 그리디문제

- 모험가 길드

  📌  Remember

  - `priority_queue` 는 내림차순 정렬임을 기억!
  - `while` 문의 조건문과 탈출문을 헷갈리지 말자
    - `while(inGuild != maxGuild && !q.empty()) {` 에서 `&&` 과 `||` 중 당연히 `&&` 을 했어야 했는데.

  ✔️   ToDoList

  - 다음에는 `queue` 말고 `vector` 이용하기
    - `queue.empty()` 와 `for` 문을 이용한 `vector` 의 순회는 둘 다 끝이 있다는 점에서 동일

