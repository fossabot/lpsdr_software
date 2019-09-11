#include "flowgraph.h"
#include "config.h"

Flowgraph::sptr Flowgraph::make(gr::basic_block_sptr source) {
  return gnuradio::get_initial_sptr(new Flowgraph(source));
}

Flowgraph::Flowgraph(gr::basic_block_sptr source)
    : gr::top_block(PACKAGE_NAME), m_source(source) {
  waterfall_sink = dispatcher_sink::make();

  connect(m_source, 0, waterfall_sink, 0);
}

Flowgraph::~Flowgraph() {}

dispatcher_sink::signal_fft_done_t Flowgraph::signal_fft_done() {
  return waterfall_sink->fft_done;
}
