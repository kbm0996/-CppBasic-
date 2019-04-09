# 단어 변환기
## 📢 개요
  공백 문자를 구분자로 하여 단어를 추출한다. 
  ```case 1```은 문자열의 각 요소들을 포인터로 접근하여 조작하는 고전적인 방법으로 구현한 것이고, ```case 2``` 는 stringstream으로 문자열을 조작하는 방법으로 구현한 것이다.
  
  >![capture](https://github.com/kbm0996/Practice-ETC/blob/master/stringExample-WordChanger/figure/run.JPG)

  
 **figure 1. Word Extractor*

## 📌전역 변수
### 🔧 ``WCHAR g_Dic[df_WORD_CNT][2][20];``
  좌측값을 우측값으로 대체하는데 사용되는 배열. df_WORD_CNT는 변환 가능한 단어 개수이고 2는 좌측값과 우측값의 한 쌍이며 20은 최대 글자 수를 의미한다.

      WCHAR g_Dic[df_WORD_CNT][2][20] =
      {
        { L"i",L"나" },{ L"you",L"너" },{ L"like",L"좋아한다" },{ L"love",L"사랑한다" },{ L"hate", L"증오한다" },
        { L"am",L"은/는" },{ L"are", L"은/는" },{L"is", L"은/는"}, { L"she", L"그녀" },{ L"he", L"그" },
        { L"boy", L"소년" },{L"a",L""}, { L"an",L"" }
      };



### 🔧 ``WCHAR g_Buff[df_STRING_MAX_LENGTH / 2][df_STRING_MAX_LENGTH];``
  변환에 성공했거나 실패한 단어들을 저장하는 임시 버퍼


## 📌함수
### 🔧 ``void StringDivide(WCHAR* pInStr);``
  구분자로 단어를 추출하는 함수.
  
  1. 인자 (Parameters)
  >const WCHAR* pInStr

  단어를 추출할 원본 문자열 
 
  2. 주요 레퍼런스
 - 문자열 복사 **wcsncpy_s();**

 최대 지정한 길이만큼 NULL문자를 만날때까지 문자열을 복사하는 함수


### 🔧 ``void StringConverse(WCHAR* pInStr, WCHAR* pOutStr);``
  g_Dic[][][]에 저장된 단어들을 검색하여 치환시켜주는 함수
  
  1. 인자 (Parameters)
  >const wstring& pInStr

  단어를 변경할 문자열 
 
  >WCHAR* pOutStr
  
  변경된 문자열을 저장할 
      
      
