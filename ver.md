# It's just made for mathmatical well-defination of abstraction... to notice circuit well,
# good mathmatics must help people to understand something easily..
# This looks like verilog, but i have no idea to well-define circuit without this way...

abstract:
    1. IF -> REG
    2. IF -> ALU
    3. REG -> ALU
    4. ALU -> MEM
    5. REG -> MEM
    6. MEM -> REG
    7. ALU -> REG
# each modules are abstracted, in this code, they are just magical boxes.
control:
    1.{
        case (IF[31:26] == 'load'):
            IF.rs -> REG.read1;
            IF.rt -> REG.write; 
        # so many cases that IF must control
    }
    2.{
        case (ALUsrc):
            IF.imed -> ALU.right # In real circuit, MUX controls this.
    }
    3.{
        case (!ALUsrc):
            REG.read_data2 -> ALU.right
        case (always):
            REG.read_data1 -> ALU.left
    }
    4.{
        case (always):
            ALU.result -> MEM.address
    }
    5.{
        case (always):
            REG.read_data2 -> MEM.write_data
    }
    6.{
        case (memtoreg):
            MEM.read_data -> REG.write_data
    }
    7.{
        case (!memtoreg):
            ALU.result -> REG.write_data
    }