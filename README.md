# 🏥 Sistema de Gestão de Clínica Médica
**SGCM – Controle de Pacientes, Consultas e Prontuários**

Este projeto foi desenvolvido em **C** com o objetivo de oferecer um sistema simples, rápido e funcional para gerenciar o fluxo de pacientes, agendamentos e prontuários médicos. O sistema é voltado para clínicas de pequeno e médio porte, visando otimizar o atendimento e a organização interna.

---

## 📦 Módulo 1: Gestão de Pacientes
### 🎯 Objetivo
Organizar o cadastro e a busca de pacientes, garantindo um registro rápido e seguro das informações essenciais.

### 🧾 Funcionalidades
- 📋 **Cadastro de Pacientes** – Nome, idade e CPF.
- 🔍 **Busca por CPF** – Localiza e exibe os dados do paciente.
- 📄 **Listagem Completa** – Mostra todos os pacientes cadastrados.

### 📊 Estrutura de Dados
- **Registro:** `Paciente` com campos nome, idade e CPF.
- **Vetor:** Armazena múltiplos cadastros para fácil listagem.

### 🧠 Regras de Negócio
- Não permitir cadastros com CPF duplicado.
- Campos obrigatórios devem ser preenchidos.

---

## 📦 Módulo 2: Agendamento de Consultas
### 🎯 Objetivo
Gerenciar consultas de forma prática, incluindo registro, cancelamento e visualização de agendamentos.

### 🧾 Funcionalidades
- 🗓️ **Agendamento** – Nome, data, especialidade, horário, local e ID.
- ❌ **Cancelamento** – Exclusão de consultas registradas.

### 📊 Estrutura de Dados
- **Registro:** `Consulta` com dados do atendimento.
- **Vetor:** Para manipular e armazenar consultas.

### 🧠 Regras de Negócio
- Não permitir agendamento duplicado para o mesmo paciente no mesmo horário.
- Cancelamentos apenas de consultas existentes.

---

## 📦 Módulo 3: Prontuários Médicos
### 🎯 Objetivo
Armazenar e manter o histórico clínico de cada paciente, permitindo consultas rápidas e atualizações contínuas.

### 🧾 Funcionalidades
- 📝 **Criação de prontuário** – Vinculado ao CPF do paciente.
- ➕ **Adição de informações** – Novos registros médicos.
- 🔍 **Busca por CPF** – Acesso rápido ao histórico médico.

### 📊 Estrutura de Dados
- **Registro:** `Prontuario` vinculado ao paciente.
- **Vetor:** Guarda múltiplas entradas para cada prontuário.

### 🧠 Regras de Negócio
- Somente pacientes cadastrados podem ter prontuários.
- Não permitir prontuários duplicados para o mesmo paciente.

---

## 🛠️ Tecnologias Utilizadas
- 💻 **Linguagem C** – Implementação da lógica e funcionalidades.
- 📘 **Markdown** – Documentação.
- ☁️ **GitHub** – Versionamento e distribuição do código.
