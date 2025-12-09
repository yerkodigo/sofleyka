# Sofle Keyboard - Configuración Sofleyka

Configuración personalizada para Sofle v1 con layout QWERTY español latinoamericano, optimizada para desarrollo de software con Home Row Mods bilaterales, símbolos de programación accesibles y controles multimedia integrados.

**Última versión: v3**

**Optimizaciones v3** (más reciente):
- Thumb cluster unificado en todas las capas para consistencia
- Controles multimedia en ADJUST (reproducción y volumen en home row)
- Método de flasheo optimizado vía QMK MSYS

**Optimizaciones v2**:
- Símbolos de programación reorganizados en fila 1 de RAISE (más accesible)
- Modificadores físicos en pulgares para combinaciones complejas (Shift+Alt+símbolo)
- Backslash y backtick ahora fáciles de encontrar
- Números duplicados eliminados, liberando espacio para símbolos frecuentes

## Estructura de capas

El keymap utiliza 4 capas:

- **BASE**: Layout QWERTY con Home Row Mods bilaterales
- **LOWER**: Navegación, teclas de función y controles multimedia
- **RAISE**: Símbolos de programación y números
- **ADJUST**: Funciones de sistema (Reset, Debug, Caps Lock)

## Home Row Mods (GACS)

Los modificadores están ubicados en la fila de inicio mediante teclas Mod-Tap que actúan de forma dual:

```
Mano izquierda:              Mano derecha:
┌─────┬─────┬─────┬─────┐    ┌─────┬─────┬─────┬─────┐
│  A  │  S  │  D  │  F  │    │  J  │  K  │  L  │  Ñ  │
├─────┼─────┼─────┼─────┤    ├─────┼─────┼─────┼─────┤
│ GUI │ Alt │Ctrl │Shift│    │Shift│Ctrl │ Alt │ GUI │
└─────┴─────┴─────┴─────┘    └─────┴─────┴─────┴─────┘
```

**Orden GACS**: GUI - Alt - Ctrl - Shift (estándar para Windows/Linux)

### Funcionamiento

- **Tap (presión rápida)**: Escribe la letra correspondiente
- **Hold (mantener presionada)**: Activa el modificador

**Ejemplo**: Ctrl+C se ejecuta manteniendo D y presionando C

**Importante**: Para mejor funcionamiento, usar el modificador en una mano y la tecla objetivo en la otra.

## Distribución de capas

### BASE

```
┌─────┬─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ ESC │  1  │  2  │  3  │  4  │  5  │             │  6  │  7  │  8  │  9  │  0  │BSPC │
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │  Q  │  W  │  E  │  R  │  T  │             │  Y  │  U  │  I  │  O  │  P  │ ´¨  │
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│SHIFT│A/GUI│S/Alt│D/Ctrl│F/Shf│  G  │             │  H  │J/Shf│K/Ctrl│L/Alt│Ñ/GUI│ENTER│
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│CTRL │  Z  │  X  │  C  │  V  │  B  │             │  N  │  M  │  ,  │  .  │  -  │SHIFT│
└─────┴─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┘
            │CTRL │ WIN │ ALT │SHIFT│LOWER│ │RAISE│ SPC │ ALT │ WIN │CTRL │
            └─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┘
```

**Mejora nueva**: Shift ahora también está disponible en el pulgar izquierdo para facilitar combinaciones como Shift+Alt+símbolo.

### LOWER - Navegación

Activación: Mantener tecla LOWER (pulgar izquierdo)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┬─────┐
│  `  │ F1  │ F2  │ F3  │ F4  │ F5  │             │ F6  │ F7  │ F8  │ F9  │ F10 │ DEL │
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ F11 │ F12 │     │     │     │             │HOME │PGDN │PGUP │ END │ INS │     │
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ GUI │ ALT │CTRL │SHIFT│     │             │  ←  │  ↓  │  ↑  │  →  │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │             │     │MUTE │VOL- │VOL+ │     │     │
└─────┴─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┘
            │     │     │     │     │█████│ │     │     │     │     │     │
            └─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┘
```

**Navegación estilo Vim**: H=←, J=↓, K=↑, L=→

### RAISE - Símbolos optimizados para programación

Activación: Mantener tecla RAISE (pulgar derecho)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┬─────┐
│  !  │  @  │  #  │  $  │  %  │  &  │             │  /  │  (  │  )  │  =  │  -  │  _  │
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  [  │  ]  │  {  │  }  │  =  │             │  +  │  \  │  |  │  '  │  `  │  ~  │
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  <  │  >  │  (  │  )  │  *  │             │  ´  │  "  │  ¿  │  ¡  │  ^  │BSPC │
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │{AltG│}AltG│\AltG│^AltG│  ?  │             │  1  │  2  │  3  │  4  │  5  │     │
└─────┴─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┘
            │     │     │     │     │     │ │█████│     │     │     │     │
            └─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┘
```

**Mejoras nuevas**:
- **Fila 1** (la más accesible): Símbolos de programación más usados - brackets `[]`, braces `{}`, operadores `= + \ |`, comillas `' ` ~`
- **Números eliminados** de fila 1: Ya están en capa BASE, no necesitan duplicarse
- **Backslash `\` visible**: Ahora en fila 1, columna 7 (fácil de encontrar)
- **Backtick `` ` `` único**: Fila 1, columna 10 (ya no duplicado)
- **Plus `+` accesible**: Fila 1, columna 6 (para combinaciones como Shift+Alt+Plus)

Símbolos reorganizados específicamente para facilitar programación y acceso a combinaciones frecuentes.

### ADJUST - Sistema y Multimedia

Activación: LOWER + RAISE simultáneamente (tri-layer)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┬─────┐
│RESET│     │     │     │     │     │             │     │     │     │     │     │DEBUG│
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │             │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│CAPS │ ◄◄  │ ►/▌▌│  ■  │ ►►  │     │             │Vol- │Vol+ │Mute │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │             │     │     │     │     │     │     │
└─────┴─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┘
            │CTRL │ WIN │ ALT │SHIFT│█████│ │█████│ SPC │ ALT │ WIN │CTRL │
            └─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┘
```

**Funciones de sistema:**
- **RESET** (ESC): Ingreso al bootloader para flasheo
- **CAPS**: Activar/desactivar Caps Lock
- **DEBUG**: Toggle debug mode

**Controles multimedia (home row):**

Mano izquierda:
- **S** (◄◄): Canción anterior
- **D** (►/▌▌): Play/Pause
- **F** (■): Stop
- **G** (►►): Canción siguiente

Mano derecha:
- **H**: Volumen -
- **J**: Volumen +
- **K**: Mute (silenciar)

## Configuración de encoders

Los encoders rotativos ejecutan diferentes funciones según la capa activa:

| Capa | Encoder Izquierdo | Encoder Derecho |
|------|-------------------|-----------------|
| BASE | Volumen -/+ | Zoom -/+ (Ctrl+Minus/Plus) |
| LOWER | Undo/Redo (Ctrl+Z/Y) | Cambiar tabs (Ctrl+Shift+Tab/Ctrl+Tab) |
| RAISE | Scroll vertical | Page Up/Down |
| ADJUST | Brillo -/+ | Media anterior/siguiente |

## Referencia rápida de símbolos

### Símbolos más usados en programación

| Símbolo | Ubicación en RAISE | Tecla física |
|---------|-------------------|--------------|
| `[` | Fila 1, col 1 | AltGr + ´ |
| `]` | Fila 1, col 2 | AltGr + + |
| `{` | Fila 1, col 3 | ´ (acento) |
| `}` | Fila 1, col 4 | + |
| `(` | Fila 2, col 3 | Shift + 8 |
| `)` | Fila 2, col 4 | Shift + 9 |
| `=` | Fila 0, col 9 / Fila 1, col 5 | Shift + 0 |
| `+` | Fila 1, col 6 | + |
| `-` | Fila 0, col 10 | - |
| `_` | Fila 0, col 11 | Shift + - |
| `\` | Fila 1, col 7 | < (backslash key) |
| `\|` | Fila 1, col 8 | Shift + < |
| `'` | Fila 1, col 9 | - (minus key) |
| `` ` `` | Fila 1, col 10 | ´ (backtick) |
| `~` | Fila 1, col 11 | AltGr + + |
| `"` | Fila 2, col 7 | Shift + 2 |
| `<` | Fila 2, col 1 | < |
| `>` | Fila 2, col 2 | Shift + < |
| `*` | Fila 2, col 5 | Shift + + |

**Nota**: "Tecla física" se refiere al keycode QMK usado, que con layout español LATAM en el OS produce el símbolo indicado.

## Combinaciones comunes

### Combinaciones de programación mejoradas

Gracias a la reorganización, estas combinaciones ahora son mucho más fáciles:

| Función | Combinación | Ejecución mejorada |
|---------|-------------|-------------------|
| Dividir terminal | Shift+Alt+Plus | Pulgar izq (Shift) + Pulgar izq (Alt) + Pulgar der (RAISE) + Plus |
| Terminal nueva | Ctrl+Shift+` | Pulgar izq (Ctrl) + Pulgar izq (Shift) + Pulgar der (RAISE) + Backtick |
| Plegar código | Ctrl+Shift+[ | Pulgar izq (Ctrl) + Pulgar izq (Shift) + Pulgar der (RAISE) + [ |
| Formatear | Alt+Shift+F | Pulgar izq (Alt) + Pulgar izq (Shift) + F |

**Ventaja clave**: Todos los modificadores están en el pulgar izquierdo, dejando la mano derecha libre para símbolos.

### Atajos de edición

| Función | Combinación | Ejecución |
|---------|-------------|-----------|
| Copiar | Ctrl+C | D (hold) + C |
| Pegar | Ctrl+V | D (hold) + V |
| Cortar | Ctrl+X | D (hold) + X |
| Deshacer | Ctrl+Z | D (hold) + Z |
| Guardar | Ctrl+S | D (hold) + S (tap) |
| Cambiar ventana | Alt+Tab | S (hold) + Tab |
| Tab anterior | Ctrl+Shift+Tab | D + F (hold) + Tab |

### Navegación con modificadores

| Función | Ejecución |
|---------|-----------|
| Seleccionar carácter | F (hold) + LOWER + H/L |
| Mover por palabras | D (hold) + LOWER + H/L |
| Seleccionar palabras | D + F (hold) + LOWER + H/L |
| Selección de bloque | S + F (hold) + LOWER + H/L |

**Alternativa con mano derecha**:
- Shift + → : J (hold) + LOWER + L
- Ctrl + → : K (hold) + LOWER + L

## Pantallas OLED

- **Mitad maestra (izquierda)**: Muestra capa activa (BASE, NAV, SYM, SYS)
- **Mitad secundaria (derecha)**: Logo personalizado

## Compilación y flasheo

### Método recomendado: QMK MSYS (Windows)

Este método es el más confiable para flashear el Sofle en Windows, evitando los problemas de comunicación serial que puede tener QMK Toolbox.

#### Procedimiento completo

**1. Abrir QMK MSYS**
   - Buscar "QMK MSYS" en el menú de Windows
   - Abrir la terminal

**2. Ejecutar comando de flasheo**
```bash
qmk flash -kb sofle/rev1 -km sofleyka
```

**3. Flashear lado izquierdo**
   - Conectar el lado **izquierdo** del teclado al USB
   - Cuando la terminal muestre "Detecting USB port, reset your controller now..."
   - Presionar el **botón reset 2 veces rápidamente** (< 1 segundo entre presiones)
   - El firmware comenzará a flashearse automáticamente
   - Esperar a que termine (verás "Flash complete")

**4. Flashear lado derecho**
   - Desconectar el lado izquierdo
   - Conectar el lado **derecho** del teclado al USB
   - **Volver a ejecutar** el comando:
     ```bash
     qmk flash -kb sofle/rev1 -km sofleyka
     ```
   - Presionar el **botón reset 2 veces rápidamente**
   - Esperar a que termine

**5. Verificar**
   - Conectar el cable TRRS entre ambas mitades
   - Conectar cualquier lado al USB
   - Probar que ambos lados funcionan correctamente

### Solo compilar (sin flashear)

Si solo quieres compilar sin flashear:

```bash
qmk compile -kb sofle/rev1 -km sofleyka
```

El archivo `.hex` se generará en `.build/sofle_rev1_sofleyka.hex`

### Métodos alternativos de ingreso al bootloader

Si el botón reset físico no funciona, puedes usar:

- **Desde teclado**: LOWER + RAISE + ESC (si tienes firmware QMK ya flasheado)
- **Hardware**: Hacer puente entre pines RST y GND en el Pro Micro

### Notas importantes

- **Bootloader Caterina**: Tiene una ventana de ~8 segundos. El doble reset extiende este tiempo.
- **Ambos lados**: Es necesario flashear AMBOS lados del teclado para que la configuración funcione correctamente.
- **Problemas con QMK Toolbox**: Si QMK Toolbox da errores de comunicación serial, usa el método de QMK MSYS descrito arriba.

## Configuración de timing

### TAPPING_TERM

Controla el tiempo de distinción entre tap y hold. Valor actual: 200ms

**Ajustar para misfires (activación accidental)**:
```c
#define TAPPING_TERM 220  // Incrementar hasta 250ms
```

**Ajustar si se siente lento**:
```c
#define TAPPING_TERM 175  // Reducir hasta 150ms
```

### Configuración actual

```c
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0
```

## Características técnicas

### Features habilitadas

El keymap tiene las siguientes características activas (definidas en `rules.mk`):

| Feature | Estado | Descripción |
|---------|--------|-------------|
| `OLED_ENABLE` | Sí | Soporte para pantallas OLED 128x32 |
| `ENCODER_MAP_ENABLE` | Sí | Configuración de encoders por capa |
| `TRI_LAYER_ENABLE` | Sí | Sistema tri-layer (LOWER + RAISE = ADJUST) |
| `OLED_DRIVER_ENABLE` | Sí | Driver para pantallas OLED |
| `RGBLIGHT_ENABLE` | No | Iluminación RGB deshabilitada |

### Definiciones en config.h

| Parámetro | Valor | Función |
|-----------|-------|---------|
| `OLED_DISPLAY_128X32` | Definido | Especifica resolución de pantalla OLED |
| `TAPPING_TERM` | 200ms | Tiempo de distinción tap/hold |
| `QUICK_TAP_TERM` | 0 | Desactiva repetición rápida en mod-tap |

### Hardware

| Componente | Especificación |
|------------|----------------|
| Development Board | Pro Micro |
| MCU | ATmega32U4 |
| Bootloader | Caterina |
| Ventana bootloader | ~8 segundos (extendido con doble reset) |

## Curva de adaptación

**Semana 1-2**: Reducción significativa de velocidad. Fase de adaptación muscular.

**Semana 3-4**: Recuperación gradual de velocidad. Los atajos comienzan a volverse automáticos.

**Post-adaptación**: Velocidad normalizada con beneficios ergonómicos. Reducción de movimiento de manos y tensión en muñecas.

## Recomendaciones de uso

### Buenas prácticas

1. Iniciar con combinaciones básicas (Ctrl+C/V) antes de avanzar a combinaciones complejas
2. Mantener el modificador presionado hasta completar la combinación
3. Utilizar manos opuestas para modificador y tecla objetivo
4. Aprovechar encoders para operaciones frecuentes (Undo/Redo, cambio de tabs)
5. Familiarizarse con navegación estilo Vim gradualmente

### Evitar

- Cambiar múltiples aspectos simultáneamente. Adopción incremental recomendada
- Esperar velocidad normal durante primeras semanas
- Subutilizar encoders. Son herramientas eficientes para flujos de trabajo

## Cambios recientes

### Optimización v3 ✅

**Consistencia de thumb cluster:**
- **Fila inferior unificada**: Todas las capas (BASE, LOWER, RAISE, ADJUST) ahora tienen la misma configuración de teclas en el thumb cluster
- **Beneficio**: Acceso consistente a modificadores (Ctrl, Win, Alt, Shift) sin importar en qué capa estés

**Controles multimedia en ADJUST:**
- **Home row multimedia**: Controles de música en teclas S, D, F, G (mano izquierda) para reproducción
- **Control de volumen**: Teclas H, J, K (mano derecha) para volumen y mute
- **Acceso rápido**: LOWER + RAISE activa controles de sistema y multimedia simultáneamente

### Optimización v2 ✅

**Reorganización de símbolos:**
- **Símbolos en RAISE optimizados**: Símbolos de programación ahora en posiciones más accesibles (fila 1)
- **Modificadores físicos en pulgar**: Shift agregado al cluster de pulgar izquierdo para combinaciones más fáciles
- **Eliminación de duplicados**: Números removidos de RAISE (ya están en BASE)
- **Backslash y backtick visibles**: Ahora en fila 1, fáciles de encontrar

**Resultado:**
- Antes: Shift+Alt+Plus requería 4 acciones complejas (F hold + S hold + RAISE + Plus)
- Ahora: Shift+Alt+Plus con pulgares (Shift thumb + Alt thumb + RAISE thumb + Plus) - mucho más ergonómico

## Mejoras futuras

- Implementación de macros personalizados en capa ADJUST
- Evaluación de capa numpad dedicada
- Posible adición de combos para símbolos muy frecuentes

## Estructura de archivos

```
sofleyka/
├── keymap.c       # Definición de capas, Home Row Mods y encoders
├── config.h       # Configuración de timing y pantalla OLED
├── rules.mk       # Features habilitadas (OLED, encoders, tri-layer)
└── readme.md      # Este archivo
```

### Archivos principales

**keymap.c**
- Enums de capas (_BASE, _LOWER, _RAISE, _ADJUST)
- Alias de Home Row Mods (HRM_A, HRM_S, HRM_D, etc.)
- Configuración de encoders por capa
- Layout de teclas para cada capa
- Función tri-layer
- Configuración OLED con logo personalizado

**config.h**
- Definición de pantalla OLED (128x32)
- Parámetros de timing para Home Row Mods
- Configuraciones de tap-hold

**rules.mk**
- Habilitación de features de QMK
- Drivers necesarios (OLED, encoders)

## Recursos adicionales

- [Home Row Mods Guide](https://precondition.github.io/home-row-mods) - Guía exhaustiva sobre home row mods
- [QMK Tap-Hold Documentation](https://docs.qmk.fm/tap_hold) - Documentación oficial de configuración tap-hold
- [Sofle Keyboard](https://josefadamcik.github.io/SofleKeyboard/) - Página oficial del teclado Sofle
- [QMK Firmware](https://qmk.fm/) - Documentación completa de QMK
