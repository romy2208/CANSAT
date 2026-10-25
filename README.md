Mapa de Módulos: 
El proyecto se divide en las siguientes partes: 
- **main.cpp**
   - Controla en general el flujo del sistem
   - A partir de "setup", inicializa las funciones y con loop el ciclo repetitivo de cada sistema
- **`communications.h` / `communications.cpp` (Módulo de Comunicaciones)**
  - Gestiona la comunicación UART con el módulo XBee (pines 16 y 17).
  - Automatiza la configuración mediante comandos AT.
  - Envía las tramas de telemetría hacia la estación terrena.
- **`sensors.h` / `sensors.cpp` (Módulo de Sensores)**
  - Se encarga de leer las variables físicas
- **`states.h` / `states.cpp` (Módulo de Estados)**
  - Implementa la máquina de estados finitos de la misión (Espera, Ascenso, Apogeo, Descenso).
- **`actuators.h` / `actuators.cpp` (Módulo de Actuadores)**
  Controla los mecanismos físicos y sistemas de liberación. 
