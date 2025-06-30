# Documentação do Projeto de Controle de Nível de Tanque

## Descrição do Projeto

Este projeto implementa um sistema de controle de nível para um tanque de água. Ele utiliza um sensor ultrassônico para medir o nível da água e uma bomba para enchê-lo até um nível desejado. Um display LCD I2C exibe o nível atual do tanque em porcentagem.

## Configuração e Execução

Para configurar e executar o projeto, siga estas etapas:

1. **Hardware:**
    - Conecte o sensor ultrassônico (pinos Trigger e Echo) às portas analógicas A3 e A2 do Arduino, respectivamente.
    - Conecte o display LCD I2C às portas I2C do Arduino (SDA, SCL).
    - Conecte o relé que controla a bomba à porta digital 0 do Arduino.
    - Certifique-se de que a bomba esteja corretamente conectada ao relé e à fonte de alimentação.
2. **Software:**
    - Abra o arquivo `src/codigoTanque.ino` na IDE do Arduino.
    - Instale as bibliotecas necessárias: `Wire`, `LiquidCrystal_I2C` e `Ultrasonic`.
    - Defina a porcentagem desejada para o nível do tanque na variável `porcentagem` (0-100%).
    - Carregue o código no Arduino.

## Explicação do Código (`src/codigoTanque.ino`)

O código é escrito em C++ para a plataforma Arduino e está organizado da seguinte forma:

- **Includes:**
    - `Wire.h`: Para comunicação I2C com o LCD.
    - `LiquidCrystal_I2C.h`: Para controlar o display LCD I2C.
    - `Ultrasonic.h`: Para interagir com o sensor ultrassônico.
- **Definições:**
    - `col`, `lin`, `ende`: Configurações do display LCD (colunas, linhas, endereço I2C).
    - `pino_trigger`, `pino_echo`: Pinos do sensor ultrassônico.
    - `pino_bomba`: Pino de controle da bomba.
- **Variáveis Globais:**
    - `lcd`: Objeto para controlar o LCD.
    - `ultrasonic`: Objeto para controlar o sensor ultrassônico.
    - `porcentagem`: Nível desejado do tanque (0-100%).
    - `altura_max`, `altura_min`: Alturas físicas correspondentes a 0% e 100% do nível do tanque.
- **`setup()`:**
    - Inicializa o LCD e o backlight.
    - Define o pino da bomba como saída e o desliga inicialmente.
    - Se a `porcentagem` for válida, calcula a altura desejada e chama `encherTanque()` para iniciar o enchimento.
- **`loop()`:**
    - Lê a distância do sensor ultrassônico.
    - Converte a distância em porcentagem do nível do tanque.
    - Exibe a porcentagem no LCD.
    - Chama `controlarBomba()` para ligar ou desligar a bomba conforme necessário.
    - Aguarda 500ms antes de repetir.
- **`encherTanque(float altura_desejada)`:**
    - Chama `controlarBomba()` para gerenciar o enchimento até a `altura_desejada`.
- **`controlarBomba(float cmMsec)`:**
    - Calcula a altura desejada com base na `porcentagem`.
    - Se a distância medida (`cmMsec`) for menor ou igual à altura desejada (tanque cheio ou acima do desejado), desliga a bomba.
    - Caso contrário (tanque abaixo do nível desejado), liga a bomba.

## Hardware Utilizado

O sistema utiliza os seguintes componentes de hardware principais (conforme inferido pela imagem no README e pelo código):

- **Microcontrolador:** Provavelmente um Arduino Uno ou similar.
- **Sensor de Nível:** Sensor ultrassônico (HC-SR04 ou similar) para medir a distância até a superfície da água.
- **Display:** Display LCD I2C de 16x2 caracteres para mostrar o nível do tanque.
- **Atuador:** Uma bomba de água, controlada por um módulo relé.
- **Placa de Circuito Impresso (PCB):** Um design de PCB customizado (`placa_PCB_tanque.rar`) provavelmente para organizar as conexões entre os componentes.
- **Fonte de Alimentação:** Necessária para alimentar o Arduino, a bomba e os sensores.

A imagem no `README.md` mostra um esquema do tanque com o sensor ultrassônico posicionado na parte superior, medindo a distância até a água. A bomba é usada para adicionar água ao tanque. O display LCD fornece feedback visual do nível.
