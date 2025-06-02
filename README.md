
# 🌊 Sistema de Alerta de Enchente — SafePlace 🚨

Este projeto tem como objetivo criar um **dispositivo de alerta de enchentes** utilizando Arduino. O sistema monitora o nível da água em tempo real, indicando se a situação está segura, em atenção ou em perigo, por meio de LEDs, buzzer e um display LCD.

---

## 🔧 Funcionalidades

- ✅ **Nível Baixo:** LED verde aceso (situação segura)
- ⚠️ **Nível Médio:** LED amarelo aceso (atenção)
- 🆘 **Nível Alto:** LED vermelho aceso + buzzer ativado (perigo de enchente)
- 📟 **Display LCD:** Mostra o status do nível da água em tempo real
- 🔊 **Alerta sonoro:** Emite som quando o nível de água ultrapassa o limite seguro

---

## 🔩 Componentes Utilizados

| Quantidade | Componente                     |
|-------------|---------------------------------|
| 1           | Arduino Uno (ou similar)       |
| 1           | Sensor Ultrassônico HC-SR04    |
| 1           | Display LCD 16x2 (com módulo I2C) |
| 1           | LED Verde                      |
| 1           | LED Amarelo                    |
| 1           | LED Vermelho                   |
| 3           | Resistores 220Ω (para os LEDs) |
| 1           | Buzzer                         |
| —           | Protoboard e Jumpers           |

---

## ⚙️ Como Funciona

- O sensor HC-SR04 mede a distância até o nível da água.
- Se a água subir (distância menor), o sistema aciona diferentes alertas:
  - 🟢 **> 20 cm:** Seguro
  - 🟡 **10 a 20 cm:** Atenção
  - 🔴 **≤ 10 cm:** Perigo — Alerta sonoro e visual
- O display LCD informa o status atual.

---

## 🔌 Esquema de Conexões

### Sensor Ultrassônico HC-SR04:
- **VCC** → 5V
- **GND** → GND
- **Trig** → Pino 9
- **Echo** → Pino 10

### LEDs:
- **Verde** → Pino 2
- **Amarelo** → Pino 3
- **Vermelho** → Pino 4

### Buzzer:
- **Positivo** → Pino 5
- **Negativo** → GND

### Display LCD I2C:
- **VCC** → 5V
- **GND** → GND
- **SDA** → A4
- **SCL** → A5

---

## 💻 Código

O código está disponível no arquivo `alerta_enchente.ino`.  
Para usar, instale a biblioteca:

- [LiquidCrystal I2C](https://github.com/johnrickman/LiquidCrystal_I2C) (para o display)

---

## 🚀 Como Executar

1. Conecte todos os componentes seguindo o esquema.
2. Abra o Arduino IDE.
3. Carregue o código `alerta_enchente.ino`.
4. Clique em **Upload** para enviar ao Arduino.
5. O sistema começará a monitorar o nível de água automaticamente.


Projeto desenvolvido para fins educacionais.  
Feito com 💙 por [Seu Nome] no projeto **SafePlace**.
