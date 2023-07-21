import {LitElement, html, css} from 'https://cdn.jsdelivr.net/gh/lit/dist@2/core/lit-core.min.js';
import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';

mermaid.initialize({ startOnLoad: false });

export class AhDiagram extends LitElement {
  static properties = {
  };

  static styles = css`
  `;

  constructor() {
    super();
    this.href = "#";
    this.primary = false;
  }

  changedSlot() {
    alert(" askdla" );
  }

  render() {
    return html`
    <slot @slotchange=${this.changedSlot}></slot>
    <div class="svg-container"></div>
    `;
  }
}

customElements.define('ah-diagram', AhDiagram);
