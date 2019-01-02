import os, struct

type
  Array = object
    code*: seq[uint32]
    pc*: int
    enabled*: bool

proc newEmptyArray*(size: int): Array =
  Array(code: newSeq[uint32](size), pc: 0, enabled: true)

proc instruction*(a: var Array): uint32 =
  assert a.enabled
  result = a.code[a.pc]
  a.pc += 1

proc `[]`*(a: Array, offset: int): uint32 =
  assert a.enabled
  a.code[offset]

proc `[]=`*(a: var Array, offset: int, data: uint32) =
  assert a.enabled
  a.code[offset] = data

proc run(codestr: string) =
  var
    len = codestr.len div 4
    code = newSeq[uint32](len)
  for i in 0..<len:
    code[i] = unpack(">I", codestr[i*4..<((i+1)*4)])[0].getUInt
  var arrays = @[Array(code: code, pc: 0, enabled: true)]
  var regs = [0u32, 0u32, 0u32, 0u32, 0u32, 0u32, 0u32, 0u32]
  while true:
    let
      i = arrays[0].instruction()
      op = i shr 28
      a = int((i shr 6) and 0x7)
      b = int((i shr 3) and 0x7)
      c = int(i and 0x7)

    case op
    of 0:
      if regs[c] != 0: regs[a] = regs[b]
    of 1: regs[a] = arrays[regs[b].int][regs[c].int]
    of 2: arrays[regs[a].int][regs[b].int] = regs[c]
    of 3: regs[a] = regs[b] + regs[c]
    of 4: regs[a] = regs[b] * regs[c]
    of 5: regs[a] = regs[b] div regs[c]
    of 6: regs[a] = not (regs[b] and regs[c])
    of 7: break
    of 8:
      arrays.add(newEmptyArray(regs[c].int))
      regs[b] = arrays.high.uint32
    of 9:
      doAssert(regs[c] != 0, "trying to abandon address 0")
      doAssert(arrays[regs[c].int].enabled, "already abandoned")
      arrays[regs[c].int].enabled = false
      arrays[regs[c].int].code = nil
    of 10:
      doAssert(regs[c] <= 255, "value to output not between 0 and 255")
      stdout.write(regs[c].chr)
    of 11:
      regs[c] = stdin.readChar.ord
      if regs[c] == 0: regs[c] -= 1
    of 12:
      if regs[b] == 0:
        arrays[0].pc = regs[c].int
      else:
        let code = arrays[regs[b].int].code
        var codeCopy = newSeq[uint32](code.len)
        deepCopy(codeCopy, code)
        arrays[0] = Array(code: codeCopy, pc: regs[c].int, enabled: true)
    of 13:
      let
        k = ((i shr 25) and 0x7).int
        v = i and 0x1ffffff
      regs[k] = v
    else: raise

when isMainModule:
  run(paramStr(1).readFile)
