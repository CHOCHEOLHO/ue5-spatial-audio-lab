# UE5 Audio Feature Test — FPS Prototype

> UE5 5.5 기반 FPS 환경에서 멀티채널 오디오 시스템을 테스트하는 개인 프로젝트입니다.

## 프로젝트 목표

| # | 목표 | 상태 |
|---|------|------|
| 1 | UE5 FPS Audio Test 샘플 프로젝트 구성 | 🔧 진행 중 |
| 2 | Wwise 기반 멀티채널 Audio Pipeline 구축 | ⏳ 예정 |
| 3 | Colormap 기반 Ambient Sound 멀티채널 분배 시스템 | ⏳ 예정 |
| 4 | 스테레오 vs 멀티채널 비교 검증 보고서 | ⏳ 예정 |

## 기술 스택

- **Engine**: Unreal Engine 5.5
- **Audio Middleware**: Audiokinetic Wwise (최신버전)
- **Monitoring**: 헤드폰 바이노럴 → 7.1 / Dolby Atmos 실환경
- **Version Control**: Git + Git LFS (GitHub)

## 폴더 구조

```
UE5AudioTest/
├── Config/              # 엔진 및 프로젝트 설정
├── Content/
│   ├── _AudioTest/      # 오디오 테스트 전용 에셋
│   │   ├── Maps/        # 테스트 레벨
│   │   ├── Blueprints/  # 오디오 테스트 BP
│   │   ├── Sounds/      # 사운드 에셋
│   │   └── Colormaps/   # Ambient 분배용 컬러맵
│   └── WwiseAudio/      # Wwise Integration 에셋
├── Plugins/
│   └── Wwise/           # Wwise UE5 Plugin
├── Source/              # C++ 소스 (필요시)
├── WwiseProject/        # Wwise 프로젝트 파일
│   ├── *.wproj
│   └── Assets/
├── .gitignore
├── .gitattributes
└── README.md
```

## 초기 설정 방법

### 1. 저장소 클론

```bash
git clone https://github.com/<your-username>/UE5AudioTest.git
cd UE5AudioTest
git lfs pull
```

### 2. Wwise 설치 요구사항

- [Audiokinetic Launcher](https://www.audiokinetic.com/download/) 설치
- Wwise 최신버전 설치 (UE5 Integration 포함)
- `WwiseProject/` 내 `.wproj` 파일로 Wwise 프로젝트 오픈

### 3. UE5 프로젝트 오픈

- `.uproject` 파일 우클릭 → *Switch Unreal Engine version* → 5.5 선택
- 프로젝트 오픈 후 Wwise Integration 자동 감지 확인

## 브랜치 전략

| 브랜치 | 용도 |
|--------|------|
| `main` | 안정 버전 |
| `dev` | 일반 개발 |
| `feature/multichannel-pipeline` | 멀티채널 파이프라인 |
| `feature/colormap-ambient` | Colormap Ambient 시스템 |
| `test/stereo-vs-multichannel` | 비교 검증 |
