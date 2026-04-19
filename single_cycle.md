Circuit of Single cycle CPU is just a **FREAK** to read and implement.
with SO MANY MUX TO CONTROL AND CONTROL BITS
To get a little, little... insigiht in this spaghetti, the thinking strategy is to **divide and merging**
For R-type, single cycle MIPS is just connect of RF and ALU, while for J-type, it is PC's comb logic.
**This may be simillar with just add-hoc, making new state and connect when a new instruction occur**
**Merging two graphs is available, could CPU also be like that?**

vars: // variables declare
    instruction[31:0];
    opcode = instrcution[31:26];
    rd = instruction[25:21];
    rt = instruction[20:16];
    rs = instruction[15:11];
    shamt = instruction[10:5];
    funct = instruction[4:0];
    immi = instruction[15:0];
    immj = instructino[26:0];
    RF{ 
        read1[4:0];
        read2[4:0];
        wr_data[31:0];
        wr_addr[4:0];
        read_data1[31:0];
        read_data2[31:0];
        write;
    };
    ALU{
        op1[31:0];
        op2[31:0];
        result[31:0];
    };



    // This is just variables this language uses, strictly, these may be also nodes of graph, but to make this report easy to look...

To_merge:
    R_type:
        1 -> RF.write;
        rd -> RF.read1;
        rt -> RF.read2;
        rs -> RF.wr_addr;
        RF.read_data1 -> ALU.OP1;
        RF.read_data2 -> ALU.OP2;
        ALU.OUT -> wr_data;
    I_type_without_sign:
        1 -> RF.write;
        rd -> RF.read1;
        rt -> RF.wr_addr;
        RF.read_data1 -> ALU.op1;
        immi -> ALU.op2;
        ALU.OUT -> RF.wr_data;
        ** RF.read2 is unknown **


// I HAVE NO TIME TO DO HOMEWORK AGAIN SO THIS IS JUST CPU THAT SUPPORTS ONLY R AND I TYPE
Result would be graph such
1 -> RF.write;
rd -> RF.read1;
RF.read_data1 -> ALU.OP1;
ALU.OUT -> RF.wr_data;
**These are just shared edges**
CONTROL1 ? RF.read_data2 : immi -> ALU.OP2;
**Compiler(?) would add temporal mux var 'CONTROL1'**
rt -> RF.read2
**Compiler would think RF.read2 as just rt, because in I-type, RF.read2 is UNKNOWN.**



Yeah but i don't know how to merge graphs and it does no help at exam, so happy.
