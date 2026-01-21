# KeebDeck Basic (有线版) 刷机指南

## 硬件信息

| 项目 | 详情 |
|------|------|
| MCU | STM32F042G6Ux (Cortex-M0, 32KB Flash, 6KB RAM, 48MHz) |
| Bootloader | STM32 DFU (内置 USB DFU, 无需外部烧录器) |
| 接口 | USB Type-C |
| 矩阵 | 6 行 x 12 列 (72 键) |
| USB VID/PID | 0xC182 / 0x1209 |

## 预编译固件

仓库内已包含编译好的固件：

```
solderparty_keebdeck_basic_default.bin  (约 23KB)
```

## 刷机步骤

### 1. 安装 dfu-util

```bash
# macOS
brew install dfu-util

# Ubuntu / Debian
sudo apt install dfu-util

# Arch
sudo pacman -S dfu-util
```

### 2. 进入 DFU 模式 (三选一)

- **Bootmagic reset**: 按住左上角键 (矩阵位置 0,0) 的同时插入 USB 线
- **物理 reset 按钮**: 短按 PCB 背面的 reset 按钮
- **QK_BOOT 键**: 如果 keymap 中映射了 `QK_BOOT`，直接按下即可

进入 DFU 模式后，`lsusb` 应能看到 STM32 DFU 设备 (0483:df11)。

### 3. 刷写固件

**方法一：直接用 dfu-util 刷写预编译 bin**

```bash
dfu-util -d 0483:df11 -a 0 -s 0x08000000:leave -D solderparty_keebdeck_basic_default.bin
```

**方法二：QMK 一键编译 + 刷写**

```bash
# 先进入 DFU 模式，然后执行：
make solderparty/keebdeck_basic:default:flash
```

**方法三：QMK Toolbox (GUI)**

1. 打开 [QMK Toolbox](https://github.com/qmk/qmk_toolbox)
2. 选择 `solderparty_keebdeck_basic_default.bin`
3. 键盘进入 DFU 模式
4. 点击 Flash

### 4. 验证

刷写完成后键盘会自动重启，即插即用。

## 从源码编译

```bash
# 配置 QMK 环境
qmk setup

# 编译
make solderparty/keebdeck_basic:default

# 输出文件为 solderparty_keebdeck_basic_default.bin
```

## 故障排查

| 问题 | 解决方法 |
|------|----------|
| `dfu-util` 找不到设备 | 确认已进入 DFU 模式；macOS 下可能需要安装 libusb: `brew install libusb` |
| 权限不足 (Linux) | 使用 `sudo dfu-util ...` 或添加 udev 规则 |
| 刷写后键盘无反应 | 检查 bin 文件是否完整 (应为 ~23KB)；重新进入 DFU 模式再刷一次 |
| macOS 无法识别 DFU | 尝试换 USB 口或换线；确认不是只充电线 |

## 相关文件

```
keyboards/solderparty/keebdeck_basic/
├── keyboard.json    # 键盘配置 (引脚、矩阵、bootloader)
├── keymaps/
│   └── default/
│       └── keymap.c # 默认键位映射
├── readme.md        # QMK 官方 README
└── rules.mk         # 编译规则
```
