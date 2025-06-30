# Controle de Nível de Tanque

Este projeto implementa um sistema automatizado para controlar o nível de água em um tanque. Ele utiliza um sensor ultrassônico para medição precisa do nível e uma bomba para manter o nível desejado, com feedback visual através de um display LCD.

![esboco_tanque](https://github.com/user-attachments/assets/a0ea0234-debf-43f2-a0e6-5d3a9be3f546)

## Visão Geral

O sistema é controlado por um microcontrolador (provavelmente Arduino) que lê os dados do sensor ultrassônico para determinar o nível atual da água. Com base em um setpoint pré-definido (porcentagem do nível desejado), o sistema aciona uma bomba para encher o tanque quando necessário. O nível atual é exibido em um display LCD.

## Estrutura do Repositório

- **/src**: Contém o código fonte do microcontrolador (`codigoTanque.ino`).
- **/hardware**: Inclui arquivos relacionados ao hardware do projeto, como o design da placa de circuito impresso (`placa_PCB_tanque.rar`).
- **/doc**: Documentação detalhada do projeto (`documentation.md`).

## Documentação Completa

Para uma descrição detalhada do projeto, instruções de configuração, explicação do código e detalhes do hardware, consulte a [Documentação Completa](./doc/documentation.md).

## Arquivos de Hardware

Os arquivos de design da placa de circuito impresso podem ser encontrados em: [`hardware/placa_PCB_tanque.rar`](./hardware/placa_PCB_tanque.rar).

## Como Contribuir

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests.

## Licença

Este projeto é distribuído sob a licença MIT. Veja o arquivo `LICENSE` para mais detalhes (Nota: arquivo LICENSE não presente atualmente, mas pode ser adicionado).
