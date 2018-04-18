
let css = {|
pre.code > code {
  color: #aaa;
  font-size: 15px;
  line-height: 1.26667;
  font-weight: 400;
  letter-spacing: -0.027em;
  font-family: "SF Mono", Menlo, monospace, "SF Pro Icons";
}

.code-block > .CodeMirror,
pre.code {
  /*box-shadow: 0 0.5px 3px #aaa;*/
  background-color: #f9fafa;
  border: 1px solid #e6e6e6;
  border-radius: 4px;
}
.code .ident, .code .pattern-ident {
    color: #333;
}

.code .module-identifier {
  color: #aa0;
}

.code .constructor,
.code .pattern-constructor {
  color: #0af;
}

.code .type-value-identifier,
.code .type-constructor,
.code .type-module-identifier {
  color: #c100af;
}

.code .type-vbl,
.code .open-module-identifier,
.code .type-module-identifier,
.code .let-module-identifier,
.code .constructor-module-identifier,
.code .switch-module-identifier,
.code .record-module-identifier,
.code .field-module-identifier
{
  color: #a0a;
}

.code .field
{
  color: #0aa;
}

.code .unused-identifier {
  color: #00a;
}

.code .declaration-var {
  color: #a50000;
}

.code .string {
    color: #c41a16;
}

.code .int {
    color: #5656cc;
}

.code .boolean {
    color: #ff8f8f;
}

.code .float {
    color: #d49523;
}

.code .operator {
  color: #9b9bff;
  font-weight: bold;
}

.type-hovered {
  text-decoration: underline;
}

.type-viewer {
  position: absolute;
  display: none;
  background-color: white;
  white-space: pre;
  padding: 8px 16px;
  pointer-events: none;
  margin-top: 10px;
  margin-left: 10px;
  box-shadow: 0px 1px 3px #e6e6e6;
  border-radius: 3px;
}

|};
