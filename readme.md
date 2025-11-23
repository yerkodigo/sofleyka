# Sofleyka - Mi config del Sofle

QWERTY español con Home Row Mods.

## Capas

- **BASE (0)** - Principal con home row mods
- **LOWER (1)** - Flechas y símbolos
- **RAISE (2)** - F1-F12
- **ADJUST (3)** - LOWER + RAISE juntos

## Home Row Mods

Mantener ASDF activa modificadores:

```
A = Shift    S = Ctrl    D = Alt    F = GUI
```

Tap normal = letra, hold = modificador.

Tiempos en config.h:
- TAPPING_TERM 200ms - si es muy sensible subirlo a 220-250
- PERMISSIVE_HOLD - detecta mejor cuando combino teclas
- QUICK_TAP_TERM 0 - evita que double-tap active el mod

## Layouts

### BASE

```
ESC   1     2     3     4     5          6     7     8     9     0    BSPC
TAB   Q     W     E     R     T          Y     U     I     O     P     ´¨
MAYUS A/Sft S/Ctl D/Alt F/GUI G          H     J     K     L     Ñ    ENTER
LCTL  Z     X     C     V     B          N     M     ,     .     /    LSFT
      CAPS  WIN  LALT  SPC  LOWER      RAISE SPC  RALT  WIN  RCTL
```

### LOWER - Navegación

```
|°    -     -     -     -     -          -     -     -    '?    ¿¡    DEL
-     -     -     -     -     -          -     -     -    ´¨    +*    }]
LSFT  -     -     -     -     -          ←     ↓     ↑     →     -    {[
LCTL  -     -     -     -     -          -     -     ,     .     /    LSFT
      CAPS  -     -   LCTL  LOWER      RAISE SPC  RALT  DEL    -
```

Flechas en HJKL estilo vim.

### RAISE - Funciones

```
F1    F2    F3    F4    F5    F6         -     -     -     -     -     -
F7    F8    F9   F10   F11   F12         -     -     -     -     -     -
-     -     -     -     -     -          -     -     -     -     -     -
LSFT  <>    -     -     -     -          -     -     -     -     -     -
       -    -     -   LCTL  LOWER      RAISE SPC    -     -     -
```

## Combos que uso

### Navegación con selección

Para seleccionar texto con Shift + Alt + flechas (lo que me costaba antes):

| Combo | Dedos |
|-------|-------|
| Shift + ← | A (hold) + LOWER + H |
| Ctrl + ← | S (hold) + LOWER + H |
| Ctrl + Shift + ← | A + S (hold) + LOWER + H |
| Alt + Shift + ← | A + D (hold) + LOWER + H |

Lo mismo para derecha pero con L en vez de H.

### Atajos del día a día

- Copiar: S + C
- Pegar: S + V
- Deshacer: S + Z
- Seleccionar todo: S + A (tap rápido la A)
- Cambiar ventana: D + TAB

## Encoders

| Capa | Izq | Der |
|------|-----|-----|
| BASE | Volumen | Brillo |
| LOWER | Scroll V | Scroll H |
| RAISE | Up/Down | PgUp/PgDn |
| ADJUST | RGB Val | RGB Hue |

## OLED

- Izq: capa activa
- Der: logo

## Compilar

```bash
qmk compile -kb sofle -km sofleyka
qmk flash -kb sofle -km sofleyka
```

## Notas

Si escribo rápido y se activan mods sin querer, agregar en config.h:
```c
#define HOLD_ON_OTHER_KEY_PRESS
```

Si 200ms es muy rápido/lento ajustar TAPPING_TERM (150-250 es el rango normal).

Los home row mods tardan 1-2 semanas en sentirse naturales.
