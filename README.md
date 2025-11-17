# g4_minimal

Geant4 몬테칼로 시뮬레이션을 수행하기 위한 강의용 템플릿 코드입니다.

이 저장소는 Geant4 시뮬레이션 수행을 위한 코드를 단계별 폴더로 구성하였습니다.

Template code for Geant4 MC simulation lecture.

This repository contains step-by-step codes for running Geant4 simulation, organized by folders.

-----

## 🔔 저장소 구조 (Repository Structure)

이 저장소는 강의 단계를 따라 각 폴더에 **완전한(standalone) 프로젝트**를 포함하고 있습니다.

  * `ch0_initial`: 시뮬레이션을 위한 최소한의 템플릿 코드 (강의 시작점)
  * `ch1_DetCon`: 1단계 (DetectorConstruction) 코드가 완료된 버전
  * `ch2_PriGen`: 2단계 (PrimaryGenerator) 코드가 완료된 버전
  * `ch3_scoring`: 3단계 (Scoring) 코드가 완료된 버전
  * `ch4_analysis`: 4단계 (Analysis) 코드가 완료된 버전

## 🌿 버전 관리 (Version Control)

각 브랜치는 특정 Geant4 버전에 대응됩니다.

  * **`main`**: 가장 최신의 강의 자료입니다.
  * **`G410`**: Geant4 10.x 버전을 지원하는 강의 자료입니다.
    * 현재 `G410` 브랜치의 코드는 2025년 11월 17일에 **Geant4 10.7.p04** 버전에서 최종적으로 테스트되었습니다. (This code in `G410` branch was tested with Geant4 version 10.7.p04 at 2025.11.17.)

-----

## 🚀 실행방법 (How to run)

**각 챕터의 폴더 안에서** 빌드를 수행해야 합니다. 예를 들어 `ch1_DetCon`을 실행하고 싶다면:

```bash
# 1. 원하는 챕터의 폴더로 이동합니다.
$ cd ch1_DetCon

# 2. 빌드 디렉토리를 생성하고 이동합니다.
$ mkdir build
$ cd build

# 3. CMake와 Make를 실행합니다.
$ cmake ..
$ make

# 4. (QT 시각화 실행)
$ ./g4_minimal

# 5. (매크로 파일 실행)
$ ./g4_minimal run.mac
```

-----

## 🔬 코드 상세 (Code Details)

각 폴더의 코드는 이전 단계의 기능을 모두 포함하고 있습니다.

### ch0\_initial

  * **DetectorConstruction**: 공기(G4\_AIR)로 채워진 1 m x 1 m x 1 m 규격의 박스형태 월드
  * **PrimaryGeneratorAction**: 기본 `G4ParticleGun` (수정 없음)

### ch1\_DetCon

  * **DetectorConstruction**: 물(G4\_WATER)로 채워진 5 cm x 5 cm x 5 cm 규격의 박스형태 물 지오메트리를 (0, 0, 10 cm) 위치에 배치

### ch2\_PriGen

  * **PrimaryGeneratorAction**: 0.662 MeV의 감마선을 원점에서 isotropic하게 발생시키도록 수정

### ch3\_scoring

  * **DetectorConstruction**: 물 박스에서의 energy deposition을 기록할 수 있도록 `G4MultiFunctionalDetector`와 `G4VPrimitiveScorer` 부여

### ch4\_analysis

  * **RunAction**: 시뮬레이션 시작/종료 시 `G4AnalysisManager`를 이용해 ROOT 파일(히스토그램, N-tuple)을 열고 저장하도록 설정
  * **EventAction**: 물 박스에 대해 기록된 energy deposition을 취합하여, 히스토그램과 N-tuple에 데이터를 기록

-----

## 작성자 (Author)

**김영수 (Young-su Kim / Evan)**

  * **이메일 (E-mail):** evandde@gmail.com
  * **홈페이지 (Homepage):** [https://evanote.mew.kr/](https://evanote.mew.kr/))