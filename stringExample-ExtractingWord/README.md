# 단어 추출하기
## 📢 개요
  특정 구분자들(「 」, 「,」, 「.」)을 기준으로 단어를 추출한다. 
  ```case 1```은 문자열의 각 요소들을 포인터로 접근하여 조작하는 고전적인 방법으로 구현한 것이고, ```case 2``` 는 stringstream으로 문자열을 조작하는 방법으로 구현한 것이다.
  
  >![capture](https://user-images.githubusercontent.com/18212066/49897556-da41d900-fe99-11e8-8cba-50480950d239.jpg)

  
 **figure 1. Word Extractor*

## 📌함수
### 🔧 ``void StringDivide(__in const WCHAR* pInStr, __out vector<wstring>& pOutTokens);``
  구분자로 단어를 추출하는 함수. ```case 1```(문자열의 각 요소들을 직접 포인터로 접근하여 조작)에 해당하는 함수
  
  1. 인자 (Parameters)
  >const WCHAR* pInStr

  단어를 추출할 원본 문자열 
 
  >vector<wstring>& pOutTokens
  
  추출한 단어들을 저장할 컨테이너
      
  2. 주요 레퍼런스
 - 문자열 복사 **wcsncpy_s();**

 최대 지정한 길이만큼 NULL문자를 만날때까지 문자열을 복사하는 함수


### 🔧 ``void StringDivide_SS(__in const wstring& pInStr, __out vector<wstring>& pOutTokens);``
  구분자로 단어를 추출하는 함수. ```case 2```(stringstream으로 문자열을 조작)에 해당하는 함수. 실제로는 내부에서 모듈 함수를 호출할 뿐 껍데기인 함수로 외부 호출이 목적
  
  1. 인자 (Parameters)
  >const wstring& pInStr

  단어를 추출할 원본 문자열 
 
  >vector<wstring>& pOutTokens
  
  추출한 단어들을 저장할 컨테이너
      
      
      
### 🔧 ``void ReplaceWstring(__in const wstring& szSource, __out wstring& szDest, const wstring& strFrom, const wstring& strTo);``
  문자열 szSource에서 문자열 strFrom을 검색하여 strTo로 모두 변경한다. 원본 문자열인 szSource는 그대로 유지되고, 변경된 문자열을 szDest에 저장한다.
  stringstream이 공백 문자를 구분자로 하여 Token을 나누기 때문에 구분자들을 모두 공백 문자로 바꿀 필요가 있다. 따라서, StringDivide_ss() 함수 내부에서 호출한다.
  
  1. 인자 (Parameters)
  >const wstring& szSource

  원본 문자열
 
  >wstring& szDest
  
  변경된 문자열을 저장할 out 변수
  
  >const wstring& strFrom
  
  찾을 문자열
  
  >const wstring& strTo
  
  변경할 문자열
  
  
  ### 🔧 ``void wTokenize(__in const wstring& pInStr, __out vector<wstring>& pOutTokens);``
  stringstream을 이용하여 단어들을 vector에 저장하는 함수
  
  1. 인자 (Parameters)
  >const wstring& pInStr

  단어를 추출할 원본 문자열 
 
  >vector<wstring>& pOutTokens
  
  추출한 단어들을 저장할 컨테이너

  
  ### 🔧 ``__int64 GetQPTick();``
  매우 정밀한(high-resolution) 시간 값을 얻기 위한 함수
  
   2. 주요 레퍼런스
 - 정밀한 시간값 얻기 **QueryPerformanceCounter()**
 
  GetTickCount()나 timeGetTime()보다 더 정밀한 시간값을 얻을 수 있다
 

  ### 🔧 ``void PrintResult(wstring szSubject, vector<wstring>& vPrintTokens);``
  vector의 모든 요소를 출력하는 함수
  
