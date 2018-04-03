
let unwrap = (m, x) => switch x { | None => failwith(m) | Some(x) => x };

let annotateSourceCode = (source, cmt, mlast, output) => {
  let annots = Cmt_format.read_cmt(cmt).Cmt_format.cmt_annots;
  let (types, bindings, externals, all_opens, locToPath) = Typing.collectTypes(annots);
  let text = Files.readFile(source) |> unwrap("Unable to read source file");
  let structure = ReadMlast.structure(mlast);
  let (highlighted, typeText) = Highlighting.highlight(text, structure, types, bindings, externals, all_opens, locToPath);
  Files.writeFile(output, Template.make(highlighted, typeText)) |> ignore;
};

let generateDocs = (cmt, output) => {
  let name = Filename.basename(cmt) |> Filename.chop_extension;
  let annots = Cmt_format.read_cmt(cmt).Cmt_format.cmt_annots;

  let input = switch annots {
  | Cmt_format.Implementation(structure) => `Structure(structure)
  | Cmt_format.Interface(signature) => `Signature(signature)
  | _ => failwith("Not a valid cmt file")
  };

  let text = Docs.generate(name, input);
  Files.writeFile(output, text) |> ignore;
};


let main = () => {
  switch (Sys.argv) {
  | [|_, source, cmt, mlast, output|] => annotateSourceCode(source, cmt, mlast, output)
  | [|_, cmt, output|] => generateDocs(cmt, output)
  | _ => {
    print_endline("\n\nUsage: docre some.re some.cmt some.mlast output.html");
  }
  }
};

main();
