# 돼지 앞구르기 로딩 모션 — LCD 16×2

[GitHub Pages 웹페이지](https://mndw100.github.io/MNDW/)

돼지가 LCD 첫째 줄 첫 칸에서 앞구르기를 하고, 한 바퀴를 마칠 때마다 둘째 줄 바닥에 균열이 늘어납니다. 균열이 끝까지 퍼지면 놀란 표정과 `OMG! DONE!`을 표시한 채 멈춥니다.

## 파일
- `index.html`: 애니메이션 미리보기, 설명과 고찰
- `run_bot.ino`: Arduino IDE 업로드용 스케치
- `images/pig-wiring.png`: Arduino Uno와 I²C LCD Fritzing 연결도
- `demo.svg`: 시뮬레이션 데모 이미지
- `wiring.svg`: 벡터 연결도

## 부품 및 연결
Arduino Uno, I²C 백팩 LCD 16×2, 점퍼선이 필요합니다.

| Arduino Uno | LCD I²C |
|---|---|
| 5V | VCC |
| GND | GND |
| A4 | SDA |
| A5 | SCL |

Arduino IDE에서 `LiquidCrystal_I2C` 라이브러리를 설치합니다. LCD 주소가 `0x27`이 아니면 스케치에서 주소를 모듈에 맞게 바꾸세요.

## GitHub Pages
저장소의 **Settings → Pages**에서 배포 소스를 `Deploy from a branch`, 브랜치 `main`, 폴더 `/(root)`로 설정합니다. 배포 완료 후 위의 페이지 링크에서 확인할 수 있습니다.

`demo.svg`는 시뮬레이션 예시이며 실제 보드 촬영 사진은 아닙니다. 업로드 후 LCD가 동작하는 사진으로 교체하면 데모 사진 요건을 충족할 수 있습니다.
