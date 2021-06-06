# g4_minimal

Geant4 몬테칼로 시뮬레이션을 수행하기 위한 템플릿 코드입니다.

이 코드는 Geant4 시뮬레이션 수행을 위한 최소한의 내용만을 담아 만들었습니다.

이 코드는 2021년 6월 6일에 Geant4 10.7.p01 버전에서 최종적으로 테스트되었습니다.

Template code for Geant4 MC simulation.

This code includes minimal requirements for running Geant4 simulation.

Tested with Geant4 version 10.7.p01 at 2021.06.06. 

---

## 실행방법 (How to run)

$ mkdir build

$ cd build

$ cmake ..

$ make

(for graphical visualization with qt)

$ ./g4_minimal

(for running simulation with "run.mac" file)

$ ./g4_minimal run.mac

---

## 코드 상세

### DetectorConstruction
- 공기(G4_AIR)로 채워진 1 m x 1 m x 1 m 규격의 박스형태 월드
- 물(G4_WATER)로 채워진 5 cm x 5 cm x 5 cm 규격의 박스형태 물 지오메트리를 0, 0, 10 cm 위치에 배치 (branch - example)
- 물 박스에서의 energy deposition을 기록할 수 있도록 primitive scorer 부여 (branch - example)

### PrimaryGeneratorAction
- 0.662 MeV의 감마선을 원점에서 isotropic하게 발생시킴 (branch - example)

### EventAction
- 물 박스에 대해 기록된 energy deposition을 취합하여, 히스토그램과 N-tuple의 형태로 기록 (branch - example)

### RunAction
- 히스토그램과 N-tuple형태로 데이터를 기록하기 위한 설정을 수행 (branch - example)

---

작성자: 김영수

이메일: evandde@gmail.com

홈페이지: https://evandde.github.io/

Author: Young-su Kim (You can call me Evan)

E-mail: evandde@gmail.com

homepage: https://evandde.github.io/
