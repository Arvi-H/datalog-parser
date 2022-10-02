cmake_minimum_required(VERSION 3.23)
project(project1_lexer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project1_lexer
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        CommentAutomaton.cpp
        CommentAutomaton.h
        EOFAutomaton.cpp
        EOFAutomaton.h
        FactsAutomaton.cpp
        FactsAutomaton.h
        IDAutomaton.cpp
        IDAutomaton.h
        LeftParenAutomaton.cpp
        LeftParenAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        QueriesAutomaton.cpp
        QueriesAutomaton.h
        QuestionAutomaton.cpp
        QuestionAutomaton.h
        RightParenAutomaton.cpp
        RightParenAutomaton.h
        RulesAutomaton.cpp
        RulesAutomaton.h
        SchemesAutomaton.cpp
        SchemesAutomaton.h
        StringAutomaton.cpp
        StringAutomaton.h
        Token.cpp
        Token.h)
