#lexer file
import ply.lex as lex
import ply.yacc as yacc

reserved={
    'var':'VAR',
    'const':'CONST',
    'let':'LET'
    }

tokens=[
    'NAME',
    'EQUAL',
    'PLUS',
    'MINUS',
    'MUL',
    'DIV',
    'INT',
    'FLOAT',
    'STRING'
    ] +list(reserved.values())

literals=',\"\''
#const a=7+9
#const a=b+c;
#const a=b+3;
#const a;

t_ignore='; \t'

def t_NAME(t):
    r'[a-zA-Z_][a-zA-Z_0-9]*'
    #print("1",t.value,t.type)
    t.type=reserved.get(t.value,'NAME') #checks for reserved words
    return t

def t_EQUAL(t):
    r'\='
    t.type='EQUAL'
    return t

def t_PLUS(t):
    r'\+'
    t.type='PLUS'
    return t

def t_MINUS(t):
    r'\-'
    t.type='MINUS'
    return t

def t_MUL(t):
    r'\*'
    t.type='MUL'
    return t

def t_DIV(t):
    r'\/'
    t.type='DIV'
    return t

def t_FLOAT(t):
    r'\d+\.\d+'
    t.type='FLOAT'
    return t

def t_INT(t):
    r'\d+'
    t.type='INT'
    return t

def t_STRING(t):
    r'\'([^\\\n]|(\\.))*?\'|\"([^\\\n]|(\\.))*?\"'
    #print("1",t.value,t.type)
    t.type=reserved.get(t.value,'STRING') #checks for reserved words
    return t


def t_error(t):
    print("Not allowed")
    t.lexer.skip(1)



def p_declaration(p):
    ''' declaration : type variable_list '''
    p[0] = ['DECLARE',p[1], p[2]]

def p_one_variable(p):
    ''' variable_list : NAME EQUAL num
                      | NAME EQUAL NAME
                      | NAME EQUAL exp
                      | NAME EQUAL STRING
                      | NAME
                      | variable_list EQUAL num '''
    p[0] = [ p[1] ]

def p_more_variables(p):
    ''' variable_list : variable_list ',' NAME'''
    p[0] = p[1]
    p[0].append(p[3])

def p_num(p):
    ''' num : INT
            | FLOAT '''
    p[0]=p[1]

def p_exp(p):
    ''' exp : exp symbol exp
            | num
            | NAME '''
    p[0]=[p[1]]

def p_symbol(p):
    ''' symbol : PLUS
               | MINUS
               | MUL
               | DIV '''
    p[0]=p[1]

    
def p_type(p):
    ''' type : VAR
             | CONST
             | LET '''
    p[0]=p[1]
def p_error(p):
    print("invalid syntax")
    raise SyntaxError
parser=yacc.yacc()
lexer=lex.lex()


while True:
    try:
        s=input()
        #print(s)
    except EOFError:
        break
    
    try:
        result=parser.parse(s)
        print("valid declaration")
    except SyntaxError:
        print("Syntax error")
